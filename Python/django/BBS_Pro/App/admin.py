from django.contrib import admin
from models import BBS, BBS_User, Comment, Category

class Admin_BBS(admin.ModelAdmin):
    list_display = ('title', 'summary', 'author', 'signature', 'posting', 'view_count', 'created_at')
    list_filter = ('created_at', 'title', 'author')
    search_fields = ('title', 'author', 'summary')
    def signature(self, obj):
        return obj.author.signature

class Admin_BBS_User(admin.ModelAdmin):
    list_display = ('user', 'email', 'photo',)
    search_fields = ('user',)
    def email(self, obj):
        return obj.user.email

class Admin_Comment(admin.ModelAdmin):
    list_display = ('BBS_id', 'user', 'datetime', 'comment')

admin.site.register(BBS, Admin_BBS)
admin.site.register(BBS_User, Admin_BBS_User)
admin.site.register(Comment, Admin_Comment)
admin.site.register(Category)
