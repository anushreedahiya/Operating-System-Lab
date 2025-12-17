#pattern printing-star half-diamonnd
echo "Enter Max number of stan that you want
read num
echo
for ((i=0; i<num; i++))
do
	for ((j=0; j<i+1; j++))
	do
		echo -n "*"     # sign is for equal to here
	done
	echo
done
for ((i=num-1; i>=0; i--))
do
	for ((j=1; j>0; j--))
	do
		echo -n "*"
	done
	echo
done
