clear
YES=y
NO=n
echo "Welcome in 42Zash, new corrector, what is your login ?"

until [ $REP == $YES ]
do
	read -p "> " LOGIN
	echo
	read -p "Ok, fine, your login is $LOGIN, right ?(y/n) " REP
	if [ $REP = $NO ]
	then
		echo
		echo "Don't worry let's do it again"
	fi	
done
