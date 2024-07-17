#!/bin/bash

checkPerfect(){
    s=0
    i=1
    n=$1
    while [ $i -le $((n / 2)) ]; do
        if [ $((n % i)) -eq 0 ]; then
        s=$((s + i))
        fi
    ((i++))
    done
    echo $s
}

echo -n "Enter lower bound: "
read low
echo -n "Enter the upper bound: "
read high

echo  
echo "Perfect numbers between $low and $high are:"

for((i=$low; i <= $high; i++)); do
    if [ $(checkPerfect $i) -eq $i ]; then
        echo -n "$i " 
    fi
done

echo 
