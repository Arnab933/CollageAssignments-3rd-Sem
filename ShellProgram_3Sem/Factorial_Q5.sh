#!/bin/sh

echo "Enter the number:"
read n

i=1
sum=1

while [ $i -le $n ]; do
    sum=$((sum*i))
    i=$((i+1))
done

echo "The factorial of $n is: $sum"