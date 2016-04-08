from django.contrib import admin
from blog.models import Employee, Author, Book,User

# Register your models here.

class BookAdmin(admin.ModelAdmin):
    list_display = ('name', )

admin.site.register([Employee, Author, User])
admin.site.register(Book, BookAdmin)