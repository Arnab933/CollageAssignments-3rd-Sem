#!/bin/sh
i=1
while [ "$i" -le 5 ]
do
    j=1
    while [ "$j" -le "$i" ]
    do
        echo -n "$j "
        j=`expr $j + 1`
    done
    echo
    i=`expr $i + 1`
done
