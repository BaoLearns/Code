from django.contrib import admin

from App.models import BBSUser, Posting, Comment, Category
# Register your models here.

class AdminBBSUser():
    pass
admin.site.register(BBSUser)
admin.site.register(Posting)
admin.site.register(Comment)
admin.site.register(Category)