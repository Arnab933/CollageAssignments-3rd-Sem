#!/bin/sh
echo "Enter the upper bound:"
read n 
echo "Enter the lower bound:"
read m

checkPrime(){
    local n=$1

    if [ "$n" -le 1 ]
    then
        echo 1
        return 
    fi

    local count=2
    while [ "$((count*count))" -le "$n" ]
    do 
        if [ "$((n%count))" -eq 0 ]
        then 
            echo 1
            return 
        fi
        count=$((count+1))
    done
    echo 0
    return 
}


echo "Twins prime numbers are:"
while [ "$m" -le "$((n-2))" ]
do
    if [ "$(checkPrime "$m")" -eq 0 ] && [ "$(checkPrime "$((m+2))")" -eq 0 ]; then
    echo "$m $((m+2))"
    fi

    m=$((m+1))
done   