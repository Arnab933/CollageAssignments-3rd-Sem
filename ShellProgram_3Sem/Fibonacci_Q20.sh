
#!/bin/sh
echo "Enter the number of terms:"
read n
arr=()
i=0
while [ $i -lt $n ]
do
    if [ $i -le 1 ];then 
        arr[$i]=$i
        i=$((i+1))
    else
        arr[$i]=$(expr ${arr[$i - 2]} + ${arr[$i - 1]})
        i=$((i + 1))
    fi
done
i=0
echo "${arr[@]}"