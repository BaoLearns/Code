#!/usr/bin/env python
#_*_ coding:utf-8 _*_
import sys
reload(sys)
sys.setdefaultencoding('utf-8')

import urllib, urllib2, re

class Tool(object):
    removeImg = re.compile('<img.*?>| {7}|')
    removeAddr = re.compile('<a.*?>|</a>')
    removeLine = re.compile('<tr>|<div>|</div>|</p>')
    removeTd = re.compile('<td>')
    removePara = re.compile('<p.*?>')
    removeBr = re.compile('<br>{1,2}')
    removeExctraTag = re.compile('<.*?>')
    def replace(self, x):
        x = re.sub(self.removeImg, '', x)
        x = re.sub(self.removeAddr, '', x)
        x = re.sub(self.removeLine, '', x)
        x = re.sub(self.removeTd, '', x)
        x = re.sub(self.removePara, '', x)
        x = re.sub(self.removeBr, '', x)
        x = re.sub(self.removeExctraTag, '', x)
        return x.strip()

class BDTB(object):
    def __init__(self, baseUrl, seeLz, maxPage):
        self.baseURL = baseURL
        self.seeLz = seeLz
        self.maxPage = maxPage
        self.content = ''
        self.tool = Tool()
    def getPage(self, pageNum):
        try:
            url = self.baseURL + self.seeLz + '&pn=' + str(pageNum)
            print url
            request = urllib2.Request(url)
            response = urllib2.urlopen(request)
            self.content = response.read().encode('utf-8')
        except urllib2.URLError, e:
            if hasattr(e, 'code'):
                print e.code
            if hasattr(e, 'reason'):
                print 'Connect the url %s fail, the reason is %s.' %(url, e.reason)

    def getTitle(self):
        page = self.getPage(1)
        pattern = re.compile('<h3 class="core_title_txt.*?>(.*?)</h3>', re.S)
        title = re.search(pattern, self.content)
        if title:
            print 'Title:', title.group()
        else:
            print 'Fail! Please check thr RE.'
    '''
    def getNumber(self):
        page = self.getPage(1)
        pattern = re.compile('<li class="l_reply_num.*?</span>.*?<span.*?>(.*?)</span>',re.S)
        result = re.findall(pattern, page)
        if result:
            print result
        else:
            print 'check thr re.'
    '''
    def getContent(self):
        for pageNum in xrange(1, self.maxPage + 1):
            self.getPage(pageNum);
            pattern = re.compile('<div id="post_content_.*?>(.*?)</div>', re.S)
            Content = re.findall(pattern, self.content)
            for content in Content:
                print self.tool.replace(content.strip())
        print 'DONE'

baseURL = 'http://tieba.baidu.com/p/3138733512'
seeLz = '?see_lz=1&'
maxPage = 5

bdtb = BDTB(baseURL, seeLz, maxPage)
bdtb.getTitle()
bdtb.getContent()
