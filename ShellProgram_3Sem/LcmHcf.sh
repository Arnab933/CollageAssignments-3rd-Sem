#!/bin/bash
calculate_Hcf() {
  local num1=$1
  local num2=$2
  local temp=0
 if [ $num2 -lt $num1 ]; then
	temp=$num2
	num2=$num1
	num1=$temp
fi
	temp=1
	i=1
while [ $i -lt $num1 ]; do
	if [ $((num1%i)) -eq 0 ] && [ $((num2%i)) -eq 0 ];then
	temp=$i
	fi
	((i++))
done
	echo $temp
	return
}
calculate_lcm(){
local num1=$1
local num2=$2
local temp=0
 if [ $num2 -lt $num1 ]; then
        temp=$num2
        num2=$num1
        num1=$temp
 fi

 for((i=1;i<=$((num1*num2));i++)); do
	temp=$((num2*i))
	if [ $((temp%num1)) -eq 0 ]; then
		break
	fi
 done
	echo $temp
	return
 }


echo "Enter the first number:"
read num1
echo "Enter second number:"
read num2
hcf=$(calculate_Hcf $num1 $num2)
lcm=$(calculate_lcm $num1 $num2)
echo "The hcf is:$hcf"
echo "The lcm is:$lcm"
