# -*- coding: utf-8 -*-
# Generated by Django 1.9.1 on 2016-04-14 08:19
from __future__ import unicode_literals

from django.conf import settings
from django.db import migrations, models
import django.db.models.deletion


class Migration(migrations.Migration):

    initial = True

    dependencies = [
        migrations.swappable_dependency(settings.AUTH_USER_MODEL),
    ]

    operations = [
        migrations.CreateModel(
            name='User',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('head_image', models.FileField(upload_to=b'')),
                ('emali', models.CharField(max_length=50, unique=True)),
                ('resume', models.CharField(max_length=400)),
                ('name', models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to=settings.AUTH_USER_MODEL)),
            ],
        ),
        migrations.CreateModel(
            name='Vote',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('votes', models.IntegerField(default=0)),
            ],
        ),
        migrations.CreateModel(
            name='VotesSystem',
            fields=[
                ('id', models.AutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('title', models.CharField(max_length=200)),
                ('start_date', models.DateTimeField()),
                ('end_date', models.DateTimeField()),
            ],
        ),
        migrations.AddField(
            model_name='vote',
            name='title',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to='Votes.VotesSystem'),
        ),
        migrations.AddField(
            model_name='vote',
            name='user',
            field=models.OneToOneField(on_delete=django.db.models.deletion.CASCADE, to='Votes.User'),
        ),
    ]
