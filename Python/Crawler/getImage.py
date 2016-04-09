import re
import urllib

def getHtml(url):
    page = urllib.urlopen(url)
    html = page.read()
    return html

def getImage(html):
    reg = r'src="(.*?\.jpg)"'
    imgre = re.compile(reg)
    imgList = re.findall(imgre, html)
    x = 1
    for imgurl in imgList:
        try:
            urllib.urlretrieve(imgurl, 'image/%s.jpg' %x)
            x += 1
        except:
            pass

url = "http://weibo.com/u/3796329175/home?wvr=5"

getImage(getHtml(url))
