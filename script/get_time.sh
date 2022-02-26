#!/bin/bash

time_str=`(time gedit) 2>&1 | grep real | awk '{print $2}'`

echo ${time_str}

time_sec=`echo -ne ${time_str} | awk -Fm '{print $2}' | awk -F. '{print $1}'`
time_min=`echo -ne ${time_str} | awk -Fm '{print $1}'`

echo $time_sec
echo $time_min

declare -i ftp_spend_time=`expr $time_sec + 60 \* $time_min`
echo ftp_spend_time:$ftp_spend_time