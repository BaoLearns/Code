#########################################################################
# File Name: sum.sh
# Author: Royecode
# Email: Royecode@163.com
# Created Time: 2015年12月24日 星期四 02时56分00秒
#########################################################################
#!/bin/bash
read max
sum=$max
min=$max
i=1
while [ $i -ne 10 ]
do
	read x
	sum=`expr $sum + $x`
	if [ $x -gt $max ]
	then
		max=$x
	elif [ $x -lt $min ]
	then
		min=$x
	fi
	i=`expr $i + 1`
done
echo sum=$sum max=$max min=$min
