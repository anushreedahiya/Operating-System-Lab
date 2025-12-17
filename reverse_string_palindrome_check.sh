#finding reverse of a given string
echo "Enter a string to reverse it and checking for palindrome: "
read str2
len=${#str2}
for ((i=$len-1; i>=0; i--));do
	rev_str= “${rev_str}${str2:$i:1}”
done
echo "Reverse of the given string: $rev_str"

# checking whether palindrome or not
if [“$str” == “$rev_str”];then
	echo “given string is palindrome”
else
	echo “ Not Palindrome string”
fi
