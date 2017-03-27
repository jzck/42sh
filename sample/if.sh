if false
then
	echo PERDU
elif false
then
	echo PERDU
elif true
then
	if false
	then
		echo PERDU
	elif
		echo GAGNE
	fi > file
else
	echo PERDU
fi
cat -e file

sleep 2
echo
echo "My sample :"
sleep 2
echo
cat sample/if.sh
