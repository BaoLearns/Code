#########################################################################
# File Name: sh05.sh
# Author: Royecode
# Email: Royecode@163.com
# Created Time: 2015年08月05日 星期三 09时57分01秒
#########################################################################
#!/bin/bash
echo Input filename
read filename
test -e $filename || echo "Filename does not exist" && exit 0
test -d $filename && echo "Filename is regular file" || echo "Filename is directory"
test -r $filename && echo "You have -r"
test -w $filename && echo "You have -w"
test -x $filename && echo "You have -x"
exit 0
