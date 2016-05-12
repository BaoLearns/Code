#_*_coding:utf-8_*_

from django import forms

class RegisterForm(forms.Form):
    '''
        Login Page
        User form
    '''
    username = forms.CharField()
    password = forms.CharField(widget = forms.PasswordInput)
    headimage = forms.FileField()
    email = forms.CharField()
    resume = forms.CharField(widget=forms.Textarea, label='简介')

class LoginForm(forms.Form):
    '''
        Login page
        User form
    '''
    username = forms.CharField()
    password = forms.CharField(widget=forms.PasswordInput)

