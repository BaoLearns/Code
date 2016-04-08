#########################################################################
# File Name: mymkdir.sh
# Author: Royecode
# Email: Royecode@163.com
# Created Time: 2015年12月24日 星期四 03时30分08秒
#########################################################################
#!/bin/bash
i=1
while [ $i -ne 100 ]
do
	rmdir "user$i"
	i=`expr $i + 1`
done

