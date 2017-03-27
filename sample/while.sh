VAR=10
while 
	   while [ $VAR -gt 0 ]  
	   do
			echo "Inside inner loop" | cat -e
			math VAR - 1
		done
		if [ $VAR -eq -42 ]
		then
			false
		else
			true
		fi
do 
	echo "I'm the execution block"
	VAR=-42
done 

sleep 2
echo
echo "My sample :"
sleep 3
echo
cat sample/while.sh
