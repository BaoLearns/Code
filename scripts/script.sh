#!/bin/bash
#Thsi program is show "Hello world!" on screen.
#echo "Whit's you name: "
#read name
#echo -e "Hello $name\n"
#readonly name
#name="fdjfkdjskfjds"
#unset name
#echo $0
#echo $1
#echo $2
#echo $*
#echo $@
#echo $#
#exit 0
#+ - * / %
a=10
b=2
echo "a = $a, b = $b"
val=`expr $a + $b`
echo "a + b = $val"
val=`expr $a - $b`
echo "a - b = $val"
val=`expr $a \* $b`
echo "a * b = $val"
val=`expr $a / $b`
echo "a / b = $val"
val=`expr $a % $b`
echo "a % b = $val"
if [ $a==$b ]
then
	echo "a is equal b"
fi

if [ $a!=$b ]
then
	echo "a not is equal b"
fi
#
