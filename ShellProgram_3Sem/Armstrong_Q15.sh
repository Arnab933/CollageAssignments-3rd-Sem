#!/bin/sh
echo "Enter a numeber:"
read n

pow(){
    local base=$1
    local expo=$2
    local s=1
    i=1
    while [ $i -le $expo ]
    do
        s=$((s*base))
        i=$((i+1))
    done
    echo "$s"
}

digit(){
    local num=$1
    local s=0
    while [ $num != 0 ]
    do
        s=$((s + 1))
        num=$((num / 10))
    done
    echo "$s"
}

p=$n
s=0
rem=0
count=$(digit "$n")
while [ $n != 0 ]
do
    rem="$((n % 10))"
    s="$((s + $(pow "$rem" "$count")))"
    n="$((n / 10))"
done
if [ "$s" -eq "$p" ]
then
    echo "The number is an armstrong number"
else
    echo "The number is not an armstrong numeber"
fi