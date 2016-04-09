# -*- coding:utf-8 -*-
import urllib
import urllib2
import re

#���°ٿ�������
class QSBK:

#��ʼ������������һЩ����
def __init__(self):
self.pageIndex = 1
self.user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
self.host = 'www.qiushibaike.com'
#��ʼ��headers
self.headers = { 'User-Agent' : self.user_agent , 'Host' : self.host}
#��Ŷ��ӵı�����ÿһ��Ԫ����ÿһҳ�Ķ�����
self.stories = []
#��ų����Ƿ�������еı���
self.enable = False
#����ĳһҳ���������ҳ�����
def getPage(self,pageIndex):
try:
url = 'http://www.qiushibaike.com/8hr/page/' + str(pageIndex)
#���������request
request = urllib2.Request(url, headers = self.headers)
# print request

#����urlopen��ȡҳ�����
response = urllib2.urlopen(request)
# print response
#��ҳ��ת��ΪUTF-8����
pageCode = response.read().decode('utf-8')
# print pageCode
return pageCode

except urllib2.URLError, e:
if hasattr(e,"reason"):
print u"�������°ٿ�ʧ��,����ԭ��",e.reason
return None

#����ĳһҳ���룬���ر�ҳ����ͼƬ�Ķ����б�
def getPageItems(self,pageIndex):
pageCode = self.getPage(pageIndex)
# print pageCode
if not pageCode:
print "ҳ�����ʧ��...."
return None
# pattern = re.compile('.*?(.*?)(.*?).*?.*?(.*?).*?.*?.*?(.*?).*?.*?',re.S)
pattern = re.compile('(.*?)(.*?).*?', re.S)
# pattern = re.compile('.*?<a.*?.*?(.*?).*?(.*?)(.*?)(.*?)',re.S)
items = re.findall(pattern, pageCode)
# print items
#�����洢ÿҳ�Ķ�����
pageStories = []
#����������ʽƥ�����Ϣ
for item in items:
#�Ƿ���ͼƬ
haveImg = re.search("img",item[0])
# print haveImg
#���������ͼƬ����������list��
if not haveImg:
#item[0]��һ�����ӵķ����ߣ�item[1]�Ƿ���ʱ��,item[2]�����ݣ�item[4]�ǵ�����
pageStories.append([item[1].strip(), item[2].strip()])
return pageStories

#���ز���ȡҳ������ݣ����뵽�б���
def loadPage(self):
#�����ǰδ����ҳ������2ҳ���������һҳ
if self.enable == True:
if len(self.stories) 0:
#��ȫ��list�л�ȡһҳ�Ķ���
pageStories = self.stories[0]
#��ǰ������ҳ����һ
nowPage += 1
#��ȫ��list�е�һ��Ԫ��ɾ������Ϊ�Ѿ�ȡ��
del self.stories[0]
#�����ҳ�Ķ���
self.getOneStory(pageStories,nowPage)

spider = QSBK()
spider.start()
