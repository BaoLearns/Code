CODEC = 'utf-8'
FILE = 'E:\Programming\python\unicode.txt'
s = u'hello world' + u'我是一个boy'
f = open(FILE, 'w')
f.write(s.encode(CODEC))
f.close()

f = open(FILE, 'r')
t = f.read()
f.close()
print t.encode(CODEC)

