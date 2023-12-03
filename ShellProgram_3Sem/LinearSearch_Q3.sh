
#!/bin/sh
echo "Enter the number of elements:"
read n
i=0
myArray=()
echo "Enter elements:"
while [ "$i" -lt "$n" ]; do
    read element
    myArray[$i]="$element"
    i=$((i + 1))
done
flag=0
echo "Enter the key element for search:"
read key
i=0
while [ "$i" -lt "$n" ]; do
   if [ "${myArray[$i]}" -eq "$key" ]
   then
   echo "Key searching is successfull"
   flag=1
    break
    fi
    i=$((i + 1))
done
if [ "$flag" -eq 0 ]
then 
    echo "Key searching is unsuccessfull"
fi