from django.template import RequestContext
from django.shortcuts import render_to_response,Http404,HttpResponseRedirect, HttpResponse
from django.contrib import auth
from django.contrib.auth.decorators import login_required

from django.db.models import Q

from OJ.models import *

import OJ.judge as judge

def ren2res(template,req,dict={}):
    if req.user.is_authenticated():
        dict.update({'user':{'id':req.user.id,'name':req.user.get_username()}})
    else:
        dict.update({'user':False})
    if req:
        return render_to_response(template,dict,context_instance=RequestContext(req))
    else:
        return render_to_response(template,dict)

# Create your views here.

def home(req):
    return ren2res("home.html",req,{})

def login(req):
    if req.method=='GET':
        if req.user.is_anonymous():
            if req.GET.get('next'):
                req.session['next']=req.GET.get('next')
            return ren2res("login.html",req,{})
        else:
            return HttpResponseRedirect("/")
    elif req.method=='POST':
        user=auth.authenticate(username=req.POST.get('name'),password=req.POST.get('pw'))
        if user is not None:
            auth.login(req,user)
            next=req.session.get('next')
            if next:
                return HttpResponseRedirect(next)
            else:
                return HttpResponseRedirect('/')
        else:
            return ren2res("login.html",req,{'err': "Wrong Username or Password!"})

def logout(req):
    auth.logout(req)
    return HttpResponseRedirect('/')

def problem(req):
    pg=int(req.GET.get('pg', 1))
    search=req.GET.get('search', "")
    if search:
        qs=Problem.objects.filter(Q(id__icontains=search)|Q(title__icontains=search)).select_related("uid__name").filter(uid__contains=search)
    else:
        qs=Problem.objects.all()

    max=qs.count()//20+1

    if(pg>max):
        raise Http404("no such page")
    start=pg-7
    if start<1:
        start=1
    end =pg+7
    if end>max:
        end=max

    lst=qs[(pg-1)*20:pg*20]

    return ren2res("problem.html",req,{'pg': pg,'page':list(range(start,end+1)),'list': lst})

def problem_detail(req,pid):
    smp=TestCase.objects.filter(pid__exact=pid).filter(sample__exact=True)
    return ren2res("problem/problem_detail.html",req,{'problem': Problem.objects.get(id=pid),'sample': smp,})

@login_required
def problem_submit(req,pid):
    if req.method=='GET':
        return ren2res("problem/problem_submit.html",req,{'problem': Problem.objects.get(id=pid)})
    elif req.method=='POST':
        sub=Submit(pid=Problem.objects.get(id=pid),uid=req.user,lang=req.POST.get('lang'))
        sub.save()
        if req.POST.get('code'):
            f=open('JudgeFiles/source/'+str(sub.id),'w')
            f.write(req.POST.get('code'))
        elif req.FILES:
            f=open('JudgeFiles/source/'+str(sub.id),'wb')
            f.write(req.FILES['file'].read())
        else:
            return ren2res("problem/problem_submit.html",req,{'problem': Problem.objects.get(id=pid),'err': "No Submit!"})
        f.close()
        judge.Judger(sub)
        return HttpResponseRedirect("/problem/"+pid+"/")


def status(req):
    '''
    pg=int(req.GET.get('pg', 1))
    search=req.GET.get('search', "")
    if search:
        qs=Problem.objects.filter(Q(id__icontains=search)|Q(title__icontains=search)).select_related("uid__name").filter(uid__contains=search)
    else:
        qs=Problem.objects.all()

    max=qs.count()//20+1

    if(pg>max):
        raise Http404("no such page")
    start=pg-7
    if start<1:
        start=1
    end =pg+7
    if end>max:
        end=max

    lst=qs[(pg-1)*20:pg*20]
    
    return ren2res("problem.html",req,{'pg': pg,'page':list(range(start,end+1)),'list': lst})
    #return HttpResponse("This status page.")
    '''
    status_obj = Submit.objects.all()
    return ren2res("status.html", req, {'status': status_obj, })

def problem_status(req, id):
    id = int(id)
    status_obj = Submit.objects.filter(pid= id)
    return ren2res("problem/problem_status.html", req, {'problem': Problem.objects.get(id=id),'status': status_obj, })


def contest(req):
    contest_obj = Contest.objects.all()
    return ren2res('contest.html', req, {'contest': contest_obj})

def contest_detail(req, id):
    id = int(id)
    contest_obj = Contest.objects.get(id=id)
    return render_to_response('contest/contest_detail.html', {'list': contest_obj,})
    #return ren2res(template='contest_detail.html', req = req, dict={'list': contest_obj})

class rank_item():
    def __init__(self, id, name, accepted = 0, submited = 0):
        self.id = id
        self.name = name
        self.accepted = accepted
        self.submited = submited
        self.ratio = 0

    def plus_accepted(self):
        self.accepted += 1

    def plus_submited(self):
        self.submited += 1

    def cat_ratio(self):
        try:
            self.ratio = self.accepted / self.submited * 100
        except ZeroDivisionError:
            self.ratio = 0.0

def rank(req):
    submit_obj = Submit.objects.all()
    user_obj = UserInfo.objects.all()
    ranks = []
    for u in user_obj:
        ranks.append(rank_item(u.id, u.id.username))
    for s in submit_obj:
        for u in ranks:
            if s.uid == u.id:
                if s.status == 0:
                    u.plus_accepted()
                u.plus_submited()
    for u in ranks:
        u.cat_ratio()
    ranks.sort(key = lambda x:(x.accepted, -x.submited), reverse=True)
    return ren2res('rank.html', req, {'rank': ranks, })
def problem_rank(req, id):
    id = int(id)
    submit_obj = Submit.objects.filter(pid = id)
    user_obj = UserInfo.objects.all()
    ranks = []
    for u in user_obj:
        ranks.append(rank_item(u.id, u.id.username))
    for s in submit_obj:
        for u in ranks:
            if s.uid == u.id:
                if s.status == 0:
                    u.plus_accepted()
                u.plus_submited()
    for u in ranks:
        u.cat_ratio()
    ranks.sort(key = lambda x:(x.accepted, -x.submited), reverse=True)
    return ren2res('problem/problem_rank.html', req, {'problem': Problem.objects.get(id=id),'rank': ranks, })


def discuss(req):
    discuss_obj = Discuss.objects.all()
    return ren2res('discuss.html', req, {'list':discuss_obj})

def problem_discuss(req, id):
    id = int(id)
    discuss_obj = Discuss.objects.filter(pid = id)
    return ren2res('problem/problem_discuss.html', req, {'problem': Problem.objects.get(id=id),'list':discuss_obj})

def about(req):
    return ren2res('about.html', req, {})