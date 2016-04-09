#_*_ encoding:utf8 _*_
from django.db import models
from django.contrib.auth.models import User

class BBS_User(models.Model):
    user = models.OneToOneField(User)
    email = models.CharField(max_length = 30,  default = 'exmaple@exm.com')
    signature = models.CharField(max_length = 128, default = 'This guy is too lazy to left anything here.')
    photo = models.ImageField(upload_to = "/home/royecode/Programming/python/django/BBS_Pro/App/upload_imgages/", default = '/home/royecode/Programming/python/django/BBS_Pro/App/upload_imgages/default.ico')
    def __unicode__(self):
        return '%s' % self.user.username
#帖子
class BBS(models.Model):
    title = models.CharField(max_length = 50)
    summary = models.CharField(max_length = 100, blank = True)
    posting = models.TextField()
    author = models.ForeignKey(BBS_User)
    view_count = models.IntegerField(default = 0)
    ranking = models.IntegerField(default = 1000)
    created_at = models.DateTimeField()
    updated_at = models.DateTimeField()

    def __unicode__(self):
        return '%s' % self.title
#评论
class Comment(models.Model):
    BBS_id = models.ForeignKey(BBS)
    user = models.CharField(max_length = 100)
    datetime = models.DateTimeField()
    comment = models.TextField()
    def __unicode__(self):
        return '%s' % self.comment

#分类
class Category(models.Model):
    name = models.CharField(max_length = 30, unique = True, blank = True)
    adminstrator = models.ForeignKey(BBS_User)
    def __unicode__(self):
        return ''.join(',', self.name)

