: '
	SINDHU P R
	20221080
'

#!/bin/bash

echo -n "Enter the number: "
read num

fact=1

if [ $num -eq 1 ]; then
	echo "The factorial is: 1"
	exit 1
fi

if [ $num -eq 0 ]; then
	echo "The factorial is: 1"
	exit 1
fi
	
while [ $num -gt 1 ]; do
	fact=$((fact * num))
	((num--))
done

echo "The factorial is: $fact"

: '

	$ ./fact.sh
Enter the number: 5
The factorial is: 120

'
