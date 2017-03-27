VAR1=0
until [ $VAR1 -gt 10 ]
do
	VAR2=0
	until [ $VAR2 -gt 10 ]
	do
		VAR3=0
		until [ $VAR3 -gt 10 ]
		do
			math VAR3 + 1
			echo "3rd is $VAR3"
		done
		math VAR2 + 1
		echo "2nd is $VAR2"
	done
	math VAR1 + 1
	echo "1st is $VAR1"
	sleep 1
done
echo
echo "VAR1: $VAR1"
echo "VAR2: $VAR2"
echo "VAR3: $VAR3"

sleep 2
echo
echo "My sample :"
sleep 2
echo
cat sample/until.sh
