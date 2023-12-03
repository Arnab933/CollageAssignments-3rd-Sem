#!/bin/sh
i=1
while [ "$i" -le 3 ]
do
    b="$i"
    while [ "$b" -ge 1 ]
    do
        echo -n "$b "
        b=`expr $b - 1`
    done
    k=2
    while [ "$k" -le $i ]
    do 
        echo -n "$k "
        k=`expr $k + 1`
    done
    echo
    i=`expr $i + 1`
done