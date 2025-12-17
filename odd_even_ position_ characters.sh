# odd and even position characters print
echo "Enter a string: "
read str
for ((i=0; i< ${#str} ; i++)); do
	if ((i%2==0)); then
		even_char+= “${str:i:1}”
	else
		odd_char+= “${str:i:1}”
	fi
done

echo "Odd position characters: $odd_char"
echo "Even position characters: $even_char"
