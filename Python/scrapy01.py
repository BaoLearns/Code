#_*_ coding:utf-8 _*_

#以下三行是避免ascii与utf8的编解码错误
import sys
reload(sys)
sys.setdefaultencoding('utf8')

#导入文件
import urllib
import urllib2
import re
import sys

#封装成一个类
class getQSBK(object):
    def __init__(self, url, user_agent, headers):
        self.url = url
        self.user_agent = user_agent
        self.headers = headers
    #获取文章的作者
    def getAuthor(self):
        try:
            request = urllib2.Request(self.url, headers = self.headers)
            response = urllib2.urlopen(request)
            content = response.read().encode('utf-8')
            #匹配的正则表达式模式
            pattern = re.compile('<h2>(.*?)</h2>', re.S)
            Author = re.findall(pattern, content)
            return Author
        #处理URLError异常
        except urllib2.URLError, e:
            if hasattr(e, 'code'):
                print e.code
            if hasattr(e, 'reason'):
                print e.reason
                return None
    
    #获取段子内容
    def getContent(self):
        try:
            request = urllib2.Request(self.url, headers = self.headers)
            response = urllib2.urlopen(request)
            content = response.read().encode('utf-8')
            #匹配正则表达式模式
            pattern = re.compile('<div class="content">(.*?)<!--.*?-->', re.S)
            Content = re.findall(pattern, content)
            return Content
        except urllib2.URLError, e:
            if hasattr(e, 'code'):
                print e.code
            if hasattr(e, 'reason'):
                print e.reason
            return None
    #输出至文件filename
    def output(self, maxPage, filename):
        print 'Analysing URL....'
        tempUrl = self.url
        Total = 0
        fd = open(filename, 'wb')
        for page in xrange(1, maxPage):
            self.url = tempUrl + str(page)
            Author = self.getAuthor()
            Content = self.getContent()
            for i in xrange(len(Author)):
                author =  Author[i].strip()
                content = Content[i].strip()
                #remove <br> <br />
                content = content.replace('<br>', '')
                content = content.replace('<br/>', '')
                fd.write("Author: %s\n" % author)
                fd.write("Content: %s\n" % content)
                fd.write('-' * 50)
                fd.write('\n')
            Total += len(Author)
            print '%s DONE, total %s.' % (self.url, len(Author))
        fd.close()
        print 'DONE, Total %s .' % Total

def main():
    #判断是否输入了输出文件
    if len(sys.argv) < 2:
        print 'Plese input file name:'
        filename = raw_input()
    else:
        filename = sys.argv[1]
    #最大的页号
    maxPage = 36
    #主页
    url = 'http://www.qiushibaike.com/textnew/page/'
    #用户代理的一些基础设置
    user_agent = 'Mozilla/4.0 (compatible; MSIE 5.5; Windows NT)'
    headers = { 'User-Agent' : user_agent }
    instance = getQSBK(url, user_agent, headers)
    instance.output(maxPage, filename)

if __name__ == '__main__':
    main()
