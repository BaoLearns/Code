# -*- coding: utf-8 -*-
# Generated by Django 1.9.1 on 2016-03-27 07:04
from __future__ import unicode_literals

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('blog', '0004_user'),
    ]

    operations = [
        migrations.AddField(
            model_name='book',
            name='published_date',
            field=models.DateTimeField(default=1),
            preserve_default=False,
        ),
        migrations.AlterField(
            model_name='book',
            name='name',
            field=models.CharField(max_length=200, verbose_name=b'\xe5\xa7\x93\xe5\x90\x8d'),
        ),
    ]
