#!/bin/bash
echo "Enter number of terms:"
read n

s=0.0

i=1
while [ $i -le $n ]; do
    s=$(echo "scale=2; $s + (1 / $i)" | bc)
    ((i++))
done

echo "Sum of the harmonic series: $s"
