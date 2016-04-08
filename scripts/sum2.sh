#########################################################################
# File Name: sum2.sh
# Author: Royecode
# Email: Royecode@163.com
# Created Time: 2015年12月24日 星期四 03时14分57秒
#########################################################################
#!/bin/bash
i=1
sum=0
while [ $i -lt 100 ]
do
	sum=`expr $sum + $i`
	i=`expr $i + 1`
done
echo $sum
