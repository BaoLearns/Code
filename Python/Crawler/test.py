import sys,re, os
reload(sys)
sys.setdefaultencoding('utf-8')

import urllib, urllib2

url = "http://www.douban.com"
request = urllib2.Request(url)

response = urllib2.urlopen(request)
contant = response.read().encode()

#partten = re.compile('<img.*?data-origin="(https:.*?\.jpg)" .*?>', re.S)
partten = re.compile('src="(.*?\.(png|gif|jpg))"')
imgs = re.findall(partten, contant)

number = 0
for httpUrl in imgs:
    print number
    print httpUrl[0]
    try:
        urllib.urlretrieve(httpUrl[0], "./image/%s.%s" % (number, httpUrl[0][len(httpUrl[0]) - 3:]))
    except:
        pass
    number += 1

print 'Total', number