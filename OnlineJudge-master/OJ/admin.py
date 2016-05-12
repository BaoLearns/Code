from django.contrib import admin

from .models import *

class UserInfoAdmin(admin.ModelAdmin):
    list_display = ['id', 'school']
    
class ProblemAdmin(admin.ModelAdmin):
    list_display = ['uid', 'published_time', 'limit_time', 'limit_memory', 'answer_lang', 'title', 'content', 'input', 'output', 'note', 'source']

class TestCaseAdmin(admin.ModelAdmin):
    list_display = ['pid', 'uid', 'time', 'sample', 'input', 'output']

class SubmitAdmin(admin.ModelAdmin):
    list_display = ['pid', 'uid', 'time', 'lang', 'status', 'run_time', 'run_memory']
    list_serach = ['pid', 'uid']
class ContestAdmin(admin.ModelAdmin):
    list_display = ['uid', 'name', 'start_time', 'end_time']
    list_filter = ['start_time', 'end_time']

class DiscussAdmin(admin.ModelAdmin):
    list_display = ['uid','pid', 'title', 'date', 'click_num', 'like']

admin.site.register(UserInfo, UserInfoAdmin)
admin.site.register(Problem, ProblemAdmin)
admin.site.register(TestCase, TestCaseAdmin)
admin.site.register(Submit, SubmitAdmin)
admin.site.register(Contest, ContestAdmin)
admin.site.register(Discuss, DiscussAdmin)