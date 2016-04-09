from django.http import HttpResponse, HttpResponseRedirect
from django.template import loader, Context
from django.shortcuts import render,render_to_response
from blog.models import Employee, Author, Book, User
from django import forms
'''
def index(request):
    return HttpResponse('<h1>Welcome to Django!</h1>')
'''
class Person(object):
    def __init__(self, name, age, sex):
        self.name, self.age, self.sex = name, age, sex
    def say(self):
        return "i'm in say(), hello world"

def index(request):
    temp = loader.get_template('index.html')
    bookList = ['python', 'C/C++', 'Java']
    userList = Employee.objects.all()
    userName = []
    for i in userList:
        userName.append(i.name)
    bookTemp = Book.objects.all()
    book = dict()
    for i in bookTemp:
        bookAuthor = ''
        for j in i.authors.all():
            bookAuthor += j.name + ' '
        book[i] = bookAuthor
    '''try:
        name = request.COOKIES['name']
    except KeyError:
        name = 'anonymous'
    '''
    try:
        name = request.session.get('name', 'anonymous')
    except KeyError:
        pass
    context = Context({'name':name,'book':book, 'userName':userName, 'user':Person('Pual', 21, 'male'), 'bookList':bookList})
    return HttpResponse(temp.render(context))

'''
def details(request, id):
    return render_to_response('index.html', {'id':id})
'''

def showAuthor(request):
    string = '\nWelcome to Django.'
    authorList = Author.objects.all()
    return render_to_response('showAuthor.html', {'string':string, 'authorList':authorList})

class UserForm(forms.Form):
    name = forms.CharField()
    password = forms.CharField(widget = forms.PasswordInput)
    headImage = forms.FileField()

class LoginForm(forms.Form):
    name = forms.CharField()
    password = forms.CharField(widget = forms.PasswordInput)

def register(request):
    if request.method == 'POST':
        form = UserForm(request.POST, request.FILES)
        if form.is_valid():
            #save the request's file
            newUser = User()
            newUser.name = form.cleaned_data['name']
            newUser.password = form.cleaned_data['password']
            newUser.headImage = form.cleaned_data['headImage']
            newUser.save()
            return HttpResponseRedirect("/login/")

    else:
        form = UserForm()
    return render_to_response('register.html', {'form':form})

def login(request):
    if request.method == 'POST':
        form = LoginForm(request.POST, request.FILES)
        if form.is_valid():
            name = form.cleaned_data['name']
            password = form.cleaned_data['password']
            user = User.objects.filter(name__exact = name, password__exact = password)
            if user:
                response = HttpResponseRedirect("/")
                #response.set_cookie('name',name, 3600)
                request.session['name'] = name
                return response
            else:
                return HttpResponseRedirect("/login/")


    else:
        form = LoginForm()
    return render_to_response('register.html', {'form':form})

def logout(request):
    response = HttpResponseRedirect('/')
    #response.delete_cookie('name')
    del request.session['name']
    return response
