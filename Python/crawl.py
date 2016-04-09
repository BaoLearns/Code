#/usr/bin/env python

from sys import argv
from os import makedirs, unlink, sep
from os.path import dirname, exists, isdir, splitext
from string import replace, find, lower
from htmllib import HTMLParser
from urllib import urlretrieve
from urlparse import urlparse, urljoin
from formatter import DumbWriter, AbstractFormatter
from cStringIO import StringIO

class Retriever(object):
    def __init__(self, url):
        self.url = url
        self.file = self.filename(url)
    def filename(self, url, deffile = 'index.html'):
        parsedurl = urlparse(url, 'http:', 0)
        path = parsedurl[1] + parsedurl[2]
        ext = splitext(path)
        print "EXT = ", ext
        if ext[1] == '':
            if path[-1] == '/':
                path += deffile
            else:
                path += '/' + diffile
        ldir = dirname(path)
        print 'PATH = ', path
        print 'ERROR::::::::', ldir
        if sep != '/':
            ldir = replace(ldir, '/', sep)
        print 'ERROR::::::::', ldir
        '''if not isdir(ldir):
            if exists(ldir):unlink(ldir)    
            makedirs(ldir)'''
        return path
    def download(self):
        try:
            retval = urlretrieve(self.url, self.file)
        except IOError:
            retval = ('***Error:invalid URL"%s"' % self.url)
        return retval

    def parseAndGetLinks(self):
        self.parser = HTMLParser(AbstractFormatter(DumbWriter(StringIO())))
        self.parser.feed(open(self.file).read())
        self.parser.close()
        return self.parsers.anchorlist



class Crawler(object):
    count = 0
    def __init__(self, url):
        self.q = [url]
        self.seen = []
        self.dom = urlparse(url)[1]
    def getPage(self, url):
        r = Retriever(url)
        retval = r.download()
        if retval[0] == '*':
            print retval, ' ... skipping parse.'
            return
        Crawler.count += 1
        print '\n(', Crawler.count, ')'
        print 'URL:', url
        print 'FILE:', retval[0]
        self.seen.append(url)
        
        links = r.parseAndGetLinks()
        for eacLink in links:
            if eachLink[:4] != 'http' and find(eachLine, '://') == -1:
                eachLink = urljoin(url, eachLink)
            print '* ', eachLink
            
            if find(lower(eachLink), 'mailto:') != -1:
                print '...discarded, mailto link!'
                continue
            if eachLink not in self.seen:
                if find(eachLink, self.dom) == -1:
                    print '... discarded, not in domain.'
                else:
                    if eachLink not in self.q:
                        self.q.append(eachLink)
                        print '...new, added to Q.'
                    else:
                        print '...discarded, already in Q.'
            else:
                print '... discarded, already processed.'
    def go(self):
        while self.q:
            url = self.q.pop()
            self.getPage(url)

def main():
    if len(argv) > 1:
        url = argv[1]
    else:
        try:
            url = raw_input('Enter start URL:')
        except (KeyboardInterrupt, EOFError):
            url = ''
    if not url:
        print 'Your input was WRONG'
        return
    robot = Crawler(url)
    robot.go()

if __name__ == '__main__':
    main()
