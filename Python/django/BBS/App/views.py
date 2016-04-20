from django.http import HttpResponseRedirect, HttpResponse
from django.shortcuts import render, render_to_response

from models import Posting

def index(request):
    return render(request, 'static/index.html', {})
    return HttpResponse("App/index.html")
    posting = Posting.objects.all()
    return render_to_response("App/index.html", {'posting':posting})

def login(request):
    pass

def logout(request):
    pass

def detail(request):
    pass
