# find occurrence of a character in a string
echo "Enter a string input: "
read str3
echo "Enter the character to search: "
read search
length3=${#str3}
occurrence=0
for ((i=0; i<$length; i++));do
	if [“${str:$i:1}” == “$search”];then
		((occurrence++))
	fi
done
echo "The character '$search' occurs $occurrence times."
