: '
	SINDHU P R
	20221080
'
#!/bin/bash

echo -n "Enter the numbers separated by spaces: "
read nums

echo -n "Enter 'asc' for ascending order and 'desc' for descending order: "
read order

if [ $order == 'asc' ]; then
	sorted=$(echo "$nums" | tr ' ' '\n' | sort -n | tr '\n' ' ')
elif [ $order == 'desc' ]; then
	sorted=$(echo "$nums" | tr ' ' '\n' | sort -nr | tr '\n' ' ')
else
	echo "Invalid Input"
fi

echo "Sorted numbers in $order order:"
echo "$sorted"

: '

$ ./sort.sh
Enter the numbers separated by spaces: 3 4 6 2 7 4
Enter asc for ascending order and desc for descending order: desc
Sorted numbers in desc order:
7 6 4 4 3 2 

'
