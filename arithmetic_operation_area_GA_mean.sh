# addition, subtraction, multiplication and division
echo "Enter the first number:
read a
echo "Enter the second number: "
read b
echo "Addition of 2 number: $(expr $a+ $b)"
echo "Subtraction: $(expr $a - $b)"
echo "Multiplication: $(expr $a \* $b)"
echo "Division: $(expr $a / $b)"

# another method
add=$(expr $a + $b)
echo "Addition: $add"

#area and perimeter of a circle
echo "Enter the radius of the circle:
read r
area=$(echo "3.14 * $r * $r" |bc)
echo "Area of the circl: $area sq.units"
echo "Perimeter of the circle: $(echo " 23.14 * $r" | bc) units"

#calculating the gross salary
echo "Enter the basic salary of the employee:
read sal
DA_per=1.65
HRA_per=0.30
DA=$(echo "$sal $DA_per/100" [bc)
HRA=$(echo "$sal $HRA_per/100" [bc) 29 gross=$(echo "$sal + $DA + $HRA" | bc) 
echo "DA: $DA"
echo "HRA: $HRA"
echo "Gross salary: $gross"

#mean salary of 1200, 1400, 1350,1800 
mean=$(echo "1200+1400+1350+1800" [bc) 
mean=$(echo "$mean/4" [bc)
echo "Mean of Basic Salary: $mean"
