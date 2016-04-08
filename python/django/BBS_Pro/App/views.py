from django.http import HttpResponse
from django.shortcuts import render_to_response
from django.template import loader

def index(request):
    return render_to_response('App/index.html')
