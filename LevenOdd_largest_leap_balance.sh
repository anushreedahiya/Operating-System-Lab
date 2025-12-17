#!/bin/sh

# Even or odd number
echo "Enter a number to check if its even or odd number:
read num
if [ $num -eq 0 ]; then
	echo "Entered number is neither even nor odd"
elif [ $((num % 2)) -eq 0 ]; then
	echo "Entered $num is Even"
else
	echo "Entered $num is Odd"
fi
echo ""

#to find largest of three numbers 16 echo "Enter the first number: " 17 read a
echo "Enter the second number: " 19 read b
echo "Enter the third number:
read c
if [ $a -ge $b ]; then
	if [ $a -gt $c ]; then
		echo "$a is the greatest number."
	else
		echo "$c is the greatest number."
else
	if [ $b -gt $c ]; then
		echo "$b is the greatest number."
	else
		echo "$c is the greatest number."
	fi 
fi

#leap year
echo "Enter the year to check for leap year:
read year
if [ $((year % 4)) -eq 0 ]; then
	if [ $((year% 100)) -ne 0 ] || [ $((year% 400)) -eq 0 ]; then 
		echo "$year is a leap year."
	fi
else
	echo "$year is not a leap year."
fi

#leap year for 1700
echo "Enter the year to check for leap year:
read year
if [ $((year % 400)) -eq 0 ]; then
	if [ $((year% 100)) -ne 0 ] || [ $((year% 4)) -eq 0 ]; then 
		echo "$year is a leap year."
	fi
else
	echo "$year is not a leap year."
fi

#balance-withdraw-tax
echo "Enter the account number: 60 "
read bal
echo "Enter the withdrawal value: "
read widraw
tax=0
if [ $widraw -lt 1500 ]; then
	tax=$(echo "$widraw*0.03" [bc)
elif [ $widraw -ge 1500 ] && [ $widraw -lt 3000 ]; then
	tax=$(echo "$widraw*0.04" | bc)
elif [ $widraw -ge 3000 ]; then
	tax=$(echo "$widraw*0.05" | bc)
fi

total_withdrawal=$(echo "$widraw + $tax" [bc)
if [ $(echo "$bal >= $total_withdrawal" [bc) -eq 1 ]; then 
	new balance=$(echo "$bal $total_withdrawal" | bc) 
	echo "Withdrawal amount: $widraw"
	echo "Tax deducted: $tax"
	echo "New balance: $new_balance"
else
	echo "insufficient balance"
fi
