# _*_ coding: utf-8 _*-

'''from django.http import HttpResponse

def first_page(request):
    return HttpResponse("<p>西餐</p>")
'''
from django.shortcuts import render

def templay(request):
    context = {}
    context['label'] = 'Hello World!'
    return render(request, 'templay.html', context)
