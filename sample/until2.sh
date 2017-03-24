ONE=0
while [ $ONE -le 10 ] 
do
	TWO=0
	while [ $TWO -le 10 ]
	do
		echo world 
		math TWO + 1;
	done
	math ONE + 1;
done > file1
