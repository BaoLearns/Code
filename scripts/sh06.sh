#!/bin/bash
echo -e "*\033[1;31m\t\tMenu\t\t\033[0m*"
echo $(uptime)
if [ test -e sh06.sh ]
then
	echo "Yes"
else
	echo "No"
fi

