from django.db import models
from django.contrib.auth.models import User

# Create your models here.

class UserInfo(models.Model):
    id = models.OneToOneField(User, primary_key=True, related_name='info')
    school = models.CharField(max_length=50, blank=True)

    def __str__(self):
        return str(self.id)

LANG_CHOICE = (
    (0, 'NONE'),
    (1, 'C'),
    (2, 'C++'),
    (3, 'Java'),
    (4, 'Python'),
    (5, 'Pascal'),
    (6, 'FORTRAN'),
    )

class Problem(models.Model):
    uid = models.ForeignKey(User)
    published_time = models.DateTimeField(auto_now_add=True)
    limit_time = models.PositiveIntegerField(default=1)
    limit_memory = models.PositiveIntegerField(default=1024*1024*128)
    answer_lang = models.PositiveSmallIntegerField(choices=LANG_CHOICE,default=0)
    title = models.CharField(max_length=254)
    content = models.TextField()
    input = models.TextField()
    output = models.TextField()
    note = models.TextField(blank=True)
    source = models.TextField(blank=True)
    #accepted_num = models.IntegerField(default=0)
    #submited_num = models.IntegerField(default=0)

    def __str__(self):
        return str(self.title)

    class Meta:
        ordering = ['published_time']

    def accepted(self):
        return len(Submit.objects.filter(status = 0))
    def submited(self):
        return Submit.objects.count()
    def ratio(self):
        try:
            ra = len(Submit.objects.filter(status = 0)) / Submit.objects.count() * 100
        except ZeroDivisionError:
            ra = 0.0
        return ra
class TestCase(models.Model):
    pid = models.ForeignKey(Problem)
    uid = models.ForeignKey(User)
    time = models.DateTimeField(auto_now_add=True)
    sample = models.BooleanField(default=False)
    input = models.TextField()
    output = models.TextField()

    def __str__(self):
        return str(self.pid)

    class Meta:
        ordering = ['time']

class Submit(models.Model):

    STATUS_CHOICE = (
        (0, 'Accepted'),
        (1, 'Waiting'),
        (2, 'Compiling'),
        (3, 'Running'),
        (-1, 'Compilation Error'),
        (-2, 'Syntax Error'),
        (-3, 'Runtime Error'),
        (-4, 'Output Limit Exceeded'),
        (-5, 'Time Limit Exceeded'),
        (-6, 'Memory Limit Exceeded'),
        (-7, 'Wrong Answer'),
        (-8, 'Presentation Error'),
    )

    pid = models.ForeignKey(Problem)
    uid = models.ForeignKey(User)
    time = models.DateTimeField(auto_now_add=True)
    lang = models.PositiveSmallIntegerField(choices=LANG_CHOICE)
    status = models.SmallIntegerField(choices=STATUS_CHOICE, default=1)
    run_time = models.PositiveSmallIntegerField(null=True)
    run_memory = models.PositiveIntegerField(null=True)

    def __str__(self):
        return str(self.pid)+'  '+str(self.uid)+'  '+str(self.lang)

    class Meta:
        ordering = ['-time']


class Contest(models.Model):
    uid = models.ForeignKey(User)
    name = models.CharField(max_length=254)
    start_time = models.DateTimeField()
    end_time = models.DurationField()
    problems = models.ManyToManyField(Problem)

    def __str__(self):
        return str(self.name)
    class Meta:
        ordering = ['start_time']

class Discuss(models.Model):
    uid = models.ForeignKey(UserInfo)
    pid = models.ForeignKey(Problem)
    date = models.DateTimeField(auto_now=True)
    title = models.CharField(max_length=100)
    discuss = models.TextField(max_length=500)
    click_num = models.IntegerField(default=0)
    like = models.IntegerField(default=0)

    def __str__(self):
        return str(self.title)

    class Meta:
        ordering = ['date']