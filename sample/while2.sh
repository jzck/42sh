ONE=11
while [ $ONE -gt 1 ] 
do
	TWO=11
	while [ $TWO -gt 1 ]
	do
		THREE=11
		while [ $THREE -gt 1 ]
		do
			echo hello
			((THREE--))
		done
		((TWO--))
	done
	((ONE--))
done
