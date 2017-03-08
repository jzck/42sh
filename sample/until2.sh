ONE=0
while [ $ONE -le 10 ] 
do
	TWO=0
	while [ $TWO -le 10 ]
	do
		THREE=0
		while [ $THREE -le 10 ]
		do
			echo world 
			((THREE++))
		done
		((TWO++))
	done
	((ONE++))
done > file1
