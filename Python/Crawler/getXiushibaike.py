# -*- coding:utf-8 -*-
import urllib
import urllib2
import re

#糗事百科爬虫类
class QSBK:

#初始化方法，定义一些变量
def __init__(self):
self.pageIndex = 1
self.user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
self.host = 'www.qiushibaike.com'
#初始化headers
self.headers = { 'User-Agent' : self.user_agent , 'Host' : self.host}
#存放段子的变量，每一个元素是每一页的段子们
self.stories = []
#存放程序是否继续运行的变量
self.enable = False
#传入某一页的索引获得页面代码
def getPage(self,pageIndex):
try:
url = 'http://www.qiushibaike.com/8hr/page/' + str(pageIndex)
#构建请求的request
request = urllib2.Request(url, headers = self.headers)
# print request

#利用urlopen获取页面代码
response = urllib2.urlopen(request)
# print response
#将页面转化为UTF-8编码
pageCode = response.read().decode('utf-8')
# print pageCode
return pageCode

except urllib2.URLError, e:
if hasattr(e,"reason"):
print u"连接糗事百科失败,错误原因",e.reason
return None

#传入某一页代码，返回本页不带图片的段子列表
def getPageItems(self,pageIndex):
pageCode = self.getPage(pageIndex)
# print pageCode
if not pageCode:
print "页面加载失败...."
return None
# pattern = re.compile('.*?(.*?)(.*?).*?.*?(.*?).*?.*?.*?(.*?).*?.*?',re.S)
pattern = re.compile('(.*?)(.*?).*?', re.S)
# pattern = re.compile('.*?<a.*?.*?(.*?).*?(.*?)(.*?)(.*?)',re.S)
items = re.findall(pattern, pageCode)
# print items
#用来存储每页的段子们
pageStories = []
#遍历正则表达式匹配的信息
for item in items:
#是否含有图片
haveImg = re.search("img",item[0])
# print haveImg
#如果不含有图片，把它加入list中
if not haveImg:
#item[0]是一个段子的发布者，item[1]是发布时间,item[2]是内容，item[4]是点赞数
pageStories.append([item[1].strip(), item[2].strip()])
return pageStories

#加载并提取页面的内容，加入到列表中
def loadPage(self):
#如果当前未看的页数少于2页，则加载新一页
if self.enable == True:
if len(self.stories) 0:
#从全局list中获取一页的段子
pageStories = self.stories[0]
#当前读到的页数加一
nowPage += 1
#将全局list中第一个元素删除，因为已经取出
del self.stories[0]
#输出该页的段子
self.getOneStory(pageStories,nowPage)

spider = QSBK()
spider.start()
