from django.conf.urls import include, url
from django.contrib import admin

from OJ import views


urlpatterns = [
    # Examples:
    # url(r'^$', 'OnlineJudge.views.home', name='home'),
    # url(r'^blog/', include('blog.urls')),

    url(r'^$', views.home),
    url(r'^login/$',views.login),
    url(r'^logout/$',views.logout),
    url(r'^problem/$', views.problem),
    url(r'^problem/([0-9]+)/$',views.problem_detail),
    url(r'^problem/([0-9]+)/submit/$',views.problem_submit),
    url(r'^admin/', include(admin.site.urls)),

    #new add
    url(r'^status/$', views.status),
    url(r'^contest/$', views.contest),
    url(r'^contest/([0-9]+)', views.contest_detail),
    url(r'^rank/$', views.rank),
    url(r'^problem/([0-9]+)/status/$', views.problem_status),
    url(r'^problem/([0-9]+)/rank/$', views.problem_rank),
    url(r'^discuss/$', views.discuss),
    url(r'^problem/([0-9]+)/discuss$', views.problem_discuss),
    url(r'^about/$', views.about),
]
