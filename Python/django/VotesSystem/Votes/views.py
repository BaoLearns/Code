#_*_coding:utf8_*_

from django.shortcuts import render, render_to_response
from django.http import HttpResponse, HttpResponseRedirect
from models import VotesSystem, User, Vote, ActiveUser
from django.template import Context
from django.utils.timezone import datetime
from form import RegisterForm, LoginForm
from django.contrib.auth.models import User as baseuser

#log file name
LOG_TXT = 'log.txt'

def write_log(dt, ip):
    '''
        write log file.
    :param request:
    :param username:
    :return:
    '''
    with open(LOG_TXT, 'a') as fp:
        fp.write('[%s] %s\n' %(dt, ip))

def read_username(ip):
    '''
        read username from ActiveUser table.
    :param request:
    :return:
    '''
    username = ''
    try:
        active = ActiveUser.objects.get(ip=ip)
        username = active.username
    except:
        pass
    return username

def write_username(request):
    try:
        active = ActiveUser.objects.get(ip=request.META['REMOTE_ADDR'])
        active.delete()
    except:
        pass

def refresh():
    '''
        refresh VotesSystem table of datebase

    '''
    VotesSystemobj = VotesSystem.objects.all()
    Voteobj = Vote.objects.all()
    for v in VotesSystemobj:
        v.total_votes = 0
        v.save()
    for v1 in Voteobj:
        for v2 in VotesSystemobj:
            if v1.title.id == v2.id:
                v2.total_votes += v1.votes
                v2.save()
                break
def index(request):
    '''
        HomePage
    '''
    #HomePage's vote list, query all vote
    #refresh()
    vote_list = VotesSystem.objects.all()
    #Context
    context = Context({'vote_list':vote_list, 'username':read_username(request.META['REMOTE_ADDR'])})
    #write current time and client ip
    write_log(datetime.now(), request.META['REMOTE_ADDR'])
    return render(request, 'index.html', context)

def register(request):
    '''
        Register page
    '''
    if request.method == 'POST':
        form = RegisterForm(request.POST, request.FILES)
        if form.is_valid():
            #save the request's file
            newUser = User()
            t = baseuser.objects.create_user(username=form.cleaned_data['username'],password=form.cleaned_data['password'])
            newUser.user = t
            newUser.head_image = form.cleaned_data['headimage']
            newUser.email = form.cleaned_data['email']
            newUser.resume = form.cleaned_data['resume']
            newUser.save()
            return HttpResponseRedirect("/login/")
        return HttpResponse('It is Work.')
    else:
        form = RegisterForm(initial={'resume':'You are best.'})
    return render_to_response('register.html', {'form':form,'username':read_username(request)})

def login(request):
    '''
        Login page
    '''
    if request.method == 'POST':
        form = LoginForm(request.POST)
        if form.is_valid():
            #parsing name and password
            username = form.cleaned_data['username']
            password = form.cleaned_data['password']
            #check username and password in datebase
            is_username = False
            is_password = False
            #print name, password
            for u in User.objects.all():
                #check name
                if u.user.username == username:
                    is_username = True
                    #check password
                    if u.user.check_password(password):
                        is_password = True
            if not is_username:
                error_info = '%s does not Exist.' % username
                print 'User does not Exist.'
                return HttpResponseRedirect('/login', {'error_info':error_info,})
            if not is_password:
                error_info = 'Wrong password.'
                return HttpResponseRedirect('/login', {'error_info':error_info,})
            #if this user is vaild, writed ip and user
            #write_username(name)
            try:

                ActiveUser.objects.create(ip=request.META['REMOTE_ADDR'], username=username)
            except:
                return HttpResponse('<h1>Error function login.</h1>')
            return HttpResponseRedirect('/vote', {'username':read_username(request),})
        else:
            return HttpResponse('<h1>Error</h1>')
    else:
        form = LoginForm()
    return render_to_response('login.html',{'form':form, })

def logout(request):
    #write_username('')
    ActiveUser.objects.get(ip=request.META['REMOTE_ADDR']).delete()

    return HttpResponseRedirect('/vote')

def details(request, id):
    id = int(id)
    vote = VotesSystem.objects.get(pk=id)
    voteobj = Vote.objects.all()
    user_list = []
    votes_list = []
    for v in voteobj:
        if v.title.id == id:
            user_list.append(v.user)
            votes_list.append(v)
    context = Context({'vote':vote, 'user_list':user_list, 'votes_list':votes_list, 'username':read_username(request.META['REMOTE_ADDR'])})
    return render(request, 'details.html', context)




def user(request, vote_id = 0, user_id = 0):
    '''
        对vote_id的user_id投票
    '''
    vote_id = int(vote_id)
    user_id = int(user_id)
    voteobj = Vote.objects.all()
    for v in voteobj:
        if v.title.id == vote_id and v.user.id == user_id:
            v.votes += 1
            v.save()
            VotesSystemobj = VotesSystem.objects.all()
            for v2 in VotesSystemobj:
                if v2.id == v.title.id:
                    v2.total_votes += 1
                    v2.save()
                    break
            return HttpResponseRedirect('/vote/%s' % vote_id)
            #return render(request, 'details.html')
    return HttpResponse("<h1>It's not Work.Vote id %s, User id %s.</h1>" %(vote_id, user_id))


def re_user(request, username):
    '''

    :param request:
    :return:
    '''
    user = User.objects.get(pk=id)
    context = {'user':user, }
    return render_to_response('user.html', context)

