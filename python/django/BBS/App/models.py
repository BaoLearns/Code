#_*_ encoding:utf8 _*_
from __future__ import unicode_literals
from django.contrib.auth.models import User
from django.db import models

#用户类
class BBSUser(models.Model):
    #用户姓名
    name = models.OneToOneField(User)
    #个性签名
    signature = models.CharField(max_length = 200, default = "This guy is too lazy to three is emtpy.")
    #发帖数
    postings = models.IntegerField(default = 0)
    #头像
    phone = models.ImageField(upload_to='home/royecode/Programming/python/django/BBS/APP/upload', default = 'home/royecode/Programming/python/django/BBS/APP/favicon.ico')

    def __unicode__(self):
        return '%s' % self.name

#帖子类别
class Category(models.Model):
    name = models.CharField(max_length = 50)
    administrator = models.ForeignKey(BBSUser)

    def __unicode__(self):
        return '%s' % self.name
#帖子类
class Posting(models.Model):
    #发帖人姓名
    author = models.OneToOneField(BBSUser, on_delete= models.CASCADE)
    #标题
    title = models.CharField(max_length = 200)
    #概要
    summer = models.CharField(max_length = 500)
    #内容
    context = models.TextField(max_length = 2000)
    #日期时间
    date_time = models.DateTimeField()
    #点赞数
    votes = models.IntegerField(default = 0)
    #浏览数
    views = models.IntegerField(default = 0)
    def __unicode__(self):
        return '%s' % self.author
#评论类
class Comment(models.Model):
    #评论的帖子
    posting_id = models.OneToOneField(Posting, on_delete= models.CASCADE)
    #评论内容
    comment = models.CharField(max_length = 2000)
    #评论时间
    date_time = models.DateTimeField()
    def __unicode__(self):
        return '%s' % self.comment