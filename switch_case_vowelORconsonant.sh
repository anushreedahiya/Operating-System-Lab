# switch case to know if given character is vowel or consonant
echo "Enter a character to check for vowel or consonant: "
read str4
case “$str4” in
	[aeiouAEIOU])
		echo “Entered character is a vowel”
		;;
	[a-zA-Z])
		echo “Entered character is a consonant”
		;;
	*)
		echo “Invalid Entry”
		;;
esac
