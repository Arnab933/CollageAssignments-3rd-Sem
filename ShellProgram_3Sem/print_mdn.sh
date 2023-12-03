#!/bin/bash

name=('M' 'i' 'd' 'n' 'a' 'p' 'o' 'r' 'e')

for((i=0; i <= ${#name[@]}; i++)); do
    echo ${name[@]:0:$i}
    sleep 0.4
done