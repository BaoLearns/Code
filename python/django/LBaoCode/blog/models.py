#_*_coding:utf-8_*_
import sys
from django.db import models

class Employee(models.Model):
    name = models.CharField(max_length=50)
    def __unicode__(self):
        return self.name
class Author(models.Model):
    name = models.CharField(max_length=50)
    def __unicode__(self):
        return self.name

class Book(models.Model):
    name = models.CharField(verbose_name = '姓名', max_length=200)
    authors = models.ManyToManyField(Author)
    #published_date = models.DateTimeField()
    def __unicode__(self):
        return self.name

class User(models.Model):
    name = models.CharField(max_length = 50)
    password = models.CharField(max_length=50)
    headImage = models.ImageField(upload_to = './upload/')    
