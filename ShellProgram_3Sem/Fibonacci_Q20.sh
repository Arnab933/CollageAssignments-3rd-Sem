
#!/bin/sh
echo "Enter the number of terms:"
read n
arr=()
i=0
while [ "$i" -lt "$n" ]
do
    if [ "$i" -le 1 ];then 
        arr[$i]="$i"
        i=`expr $i + 1`
    else
        arr[$i]=$(expr ${arr[$i - 2]} + ${arr[$i - 1]})
        i=`expr $i + 1`
    fi
done
i=0
while [ "$i" -lt "$n" ]
do
    echo -n "${arr[$i]} "
    i=`expr $i + 1`
done