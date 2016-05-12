#_*_coding:utf-8_*_

from __future__ import unicode_literals
from django.contrib.auth.models import User as baseuser
from django.db import models

class VotesSystem(models.Model):
    '''
        This table construct of Votes System.
    '''
    title = models.CharField(max_length=200, blank=False)
    description = models.CharField(max_length=500, blank=True)
    #published_date = models.DateField()
    start_date = models.DateTimeField()
    end_date = models.DateTimeField()
    total_votes = models.IntegerField(default=0)
    def __unicode__(self):
        return '%s' % self.title
    '''class Meta(object):
        ordering = ['published_date']
    '''
class User(models.Model):
    '''
        This table construct of User.
    '''
    user = models.OneToOneField(baseuser, unique=True)
    head_image = models.FileField(upload_to='./upload', default='Bus.png')
    email = models.EmailField(default='exmaple@example.com')
    resume = models.CharField(max_length=400, default='This guy is lazy that what also did not leave here.')

    def __unicode__(self):
        return '%s\n%s' % (self.user.username,self.resume)
class Vote(models.Model):
    '''
        This table construct of Vote.
    '''
    title = models.ForeignKey(VotesSystem)
    user = models.ForeignKey(User)
    votes = models.IntegerField(default=0)
    def __unicode__(self):
        return '%s %s' % (self.title.title, self.votes)

class ActiveUser(models.Model):
    '''
        This table construct of Active User
        ip and name
    '''
    ip = models.CharField(max_length=50, unique=True)
    username = models.CharField(max_length=50)
    def __unicode__(self):
        return '[%s] %s' %(self.ip, self.username)