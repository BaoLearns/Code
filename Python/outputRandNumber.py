#_*_ coding:utf-8 _*_
from random import randint

#输入数据文件名
FILENAME = 'Number.txt'
#划分为多少个文件
SIZE = 40
#划分出10个小文件的文件名
SPLIT_FILENAME = 'Split'

#生成10^7个范围在[0, 10^7)的数
def Output():
    #清空原文件
    FILENAME_fd = open(FILENAME, 'wb')
    FILENAME_fd.write('')
    FILENAME_fd.close()
    #10^7个数分为1K次产生,每次产生1W个数,这样减少内存的同时使用情况
    for i in xrange(1000):
        FILENAME_fd = open(FILENAME, 'a')
        #1w个数的链表
        L = [x for x in xrange(10000)]
        for j in xrange(10000):
            #随机产生[0, len(L))的下标,将数写入文件,并从链表中删除
            index = randint(0, len(L) - 1)
            FILENAME_fd.write(str(i * 10000 + L[index]))
            FILENAME_fd.write('\n')
            del L[index]
        FILENAME_fd.close()

#将原文件划分为SIZE个文件
def Split():
    FILENAME_fd = open(FILENAME, 'r')
    SPLIT_FILENAME_fd = [open(SPLIT_FILENAME + str(i) + '.txt', 'wb') for i in xrange(SIZE)]
    for i in FILENAME_fd.readlines():
        number = int(i.strip())
        index = number / (10000000 / 40)
        SPLIT_FILENAME_fd[index].write(str(number))
        SPLIT_FILENAME_fd[index].write('\n')
    FILENAME_fd.close()
    for fd in SPLIT_FILENAME_fd:
        fd.close()

#统计每个小文件数的个数
def Count():
    SPLIT_FILENAME_fd = [open(SPLIT_FILENAME + str(i) + '.txt', 'r') for i in xrange(SIZE)]
    for fd in SPLIT_FILENAME_fd:
        print '%s有[%s]个数' % (fd.name, sum([ 1 for j in fd.readlines()]))
        fd.close()

#对每个小文件分别排序并输出至原文件
def Sort():
    FILENAME_fd = open(FILENAME, 'wb')
    SPLIT_FILENAME_fd = [open(SPLIT_FILENAME + str(i) + '.txt', 'r') for i in xrange(SIZE)]
    for fd in SPLIT_FILENAME_fd:
        #将fd的所有数读进来并排序
        L = [int(x) for x in fd.readlines()]
        L.sort()
        for x in L:
            FILENAME_fd.write(str(x))
            FILENAME_fd.write('\n')
        fd.close()
    FILENAME_fd.close()

if __name__ == '__main__':
    Output()
    Split()
    Count()
    Sort()
    print 'DONE'
