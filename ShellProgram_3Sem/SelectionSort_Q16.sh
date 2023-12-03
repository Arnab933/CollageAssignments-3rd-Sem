
#!/bin/sh
echo "Enter the number of elements in the array:"
read num_elements
i=0
arr=()
echo "Enter elements of the array:"
while [ "$i" -lt "$num_elements" ]
do
    read element
    arr["$i"]="$element"
    i="$((i+1))"
done

i=0
j=0
min_idx=0
temp=0
while [ "$i" -lt "$num_elements" ]
do
    min_idx="$i"
    j="$((i + 1))"
   while [ "$j" -lt "$num_elements" ]
   do
    if [ "${arr["$j"]}" -lt "${arr["$min_idx"]}" ]
        then
            min_idx="$j"
        fi
    j="$((j+1))"
    done
    temp="${arr["$min_idx"]}"
    arr["$min_idx"]="${arr["$i"]}"
    arr["$i"]="$temp"
 i="$((i+1))"
done

# Output: Display the sorted array
echo "The sorted array is:"
i=0
while [ "$i" -lt "$num_elements" ]
do
    echo -n "${arr["$i"]} "
    i="$((i+1))"
done