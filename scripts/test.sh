#########################################################################
# File Name: test.sh
# Author: Royecode
# Email: Royecode@163.com
# Created Time: 2015年12月24日 星期四 03时20分41秒
#########################################################################
#!/bin/bash
i=1
sum=0
while [ $i -lt 100 ]
do
	if [ `expr $i % 3` -eq 0 ] 
	then
		sum=`expr $sum + $i`
	else
		echo "$i mode 3 != 0"
	fi
	i=`expr $i + 1`
done
echo sum=$sum
