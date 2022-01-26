#!/bin/bash

stty -F /dev/ttyUSB1 cs8 -parenb -cstopb -echo raw speed 115200

cat /dev/ttyUSB1 | while read line
do
    if [ "$byte" = $'\r' ]
    then
        echo "recv \r"
    fi
    
    if [ "$byte" = $'\n' ]
    then
        echo "recv \n"
    fi
    #echo -ne ${byte}
    #printf '%c' $byte

    date=`date +%F_%T`
    printf '%s %s\n' "[${date}] $line"

    #echo -ne $byte | hexdump -c
    #echo -en recv:$byte
done