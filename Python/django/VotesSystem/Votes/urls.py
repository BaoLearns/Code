from django.conf.urls import url
from views import index, details, user

urlpatterns = [

    url(r'^$', index, name = 'index'),
    url(r'^(\d+)/$', details, name = 'details'),
    url(r'^(\d+)/user/(\d+)/$', user, name ='name'),
    #url(r'^vote/(?P<id>[0-9]+)$', vote, name = 'vote'),
    #(r'^css/(?Ppath.*)$', 'django.views.static.serve', {'document_root': './temp'}),
    #(r'^js/(?P/pathpath.*)$', 'django.views.static.serve', {'document_root': '/var/www/django-demo/js'}),
    #(r'^images/(?P/pathpath.*)$', 'django.views.static.serve', {'document_root': '/var/www/django-demo/images'}),
]
