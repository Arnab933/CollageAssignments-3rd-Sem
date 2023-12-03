#!/bin/sh
echo "Enter a number:"
read n

echo "The multiplication table is:"
i=1
while [ "$i" -le 10 ]
do
    printf ""$n"\t"
    i="$((i+1))"
done
echo 
i=1
while [ "$i" -le 10 ]
do
    printf ""$i"\t"
    i="$((i+1))"
done
echo 
i=1
while [ "$i" -le 10 ]
do
    printf ""$((i*n))"\t"
    i="$((i+1))"
done