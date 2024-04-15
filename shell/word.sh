: '
	SINDHU P R
	20221080
'

echo -n "Enter the word to be searched: "
read word

echo -n "Enter the file to be searched in: "
read sfile

count=$(grep -o -w "$word" "$sfile" | wc -l)

echo "$word appears $count times in $sfile"

: '

	$ ./word.sh
Enter the word to be searched: hi
Enter the file to be searched in: a.txt
hi appears 2 times in a.txt

	a.txt:
heyy 
helloo
hi
no
hey
yea
hi

'
