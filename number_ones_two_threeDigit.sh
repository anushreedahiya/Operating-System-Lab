#case...esac statements
#check whether the number is one digit, two digit, three digit
echo Enter a number:
read num
case $num in
[0-9])
echo “Entered number $num is single digit number”
;;    # marks the end of 1st statement

[0][0-9])
num=”${num#0}”
echo “Entered number is single digit”
;;

[1-9][0-9]) 
echo “Entered number is two digit number.”
;;

[1-9][0-9][0-9])
echo “Entered number is three digit number”
;;

*)  # default syntax
echo “Number is greater than 999”
;;

esac