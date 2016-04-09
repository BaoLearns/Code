from urllib import urlretrieve

def firstNonBlank(lines):
    for eachLine in lines:
        #if not eachLine.strip():
        #   continue
        #return eachLine
        print eachLine
def firstLast(webpage):
    f = open(webpage, 'r')
    lines = f.readlines()
    f.close()
    firstNonBlank(lines)
    #print firstNonBlank(lines)
    #lines.reverse()
    #print firstNonBlank(lines)
def download(url = 'http://www.163.com', process = firstLast):
    try:
        retval = urlretrieve(url)[0]
    except IOError:
        retval = None
    if retval:
        process(retval)
if __name__ == '__main__':
    download()
