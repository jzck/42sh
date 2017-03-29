VAR=10
if true
then
    echo "Salut" ; echo "Correcteur"
	while [ $VAR -gt 0 ]
	do
		until true
		do
			echo KO SI JE M AFFICHE
		done
		if true
		then
			echo OK SI JE M AFFICHE
		elif [ -f Makefile ]
		then
			echo KO SI JE M AFFICHE
		else
			echo KO SI JE M AFFICHE
		fi
		echo "Encore un tour"
		math VAR - 1
	done
fi

sleep 2
echo
echo "My sample :"
sleep 3
echo
cat sample/mix.sh
