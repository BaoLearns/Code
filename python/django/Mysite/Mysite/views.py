# _*_ coding: utf-8 -*-

from django.http import HttpResponse

def first_page(request):
    return HttpResponse("<p>hello world</p>")
