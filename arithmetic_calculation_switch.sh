#case...esac statements
#doing different mathematical calculation
echo "Enter first number: "
read a
echo "Enter second number: "
read b

while true; do
echo “Enter 1 for addition”
echo “Enter 2 for subtraction”
echo “Enter 3 for division”
echo “Enter 4 for multiplication”
echo “Enter 5 to exit”
read num

case $num in
[1])
	echo “Addition of given numbers: $(($a + $b))”
;;

[2])
	echo “Subtraction of given numbers: $(($a - $b))”
;;

[3]) 
	if [ $b -eq 0 ]; then
		echo “Not divisible”
	else
		echo “Division of given numbers: $(($a / $b))”
	fi
;;

[4])
	echo “Multiplication of given numbers: $(($a * $b))”
;;

[5])
	echo “Exiting the code”
	break
;;

*)
	echo “Invalid Entry”
;;

esac
done
