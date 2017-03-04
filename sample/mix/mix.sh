if ls
then
    pwd ; echo "Salut"
	while ls
	do
		until pwd
		do
			echo KO SI JE M AFFICHE
		done
		if cat faux
		then
			echo BONJOUR MAKEFILE
		elif [ -f Makefile ]
		then
			echo BONJOUR MAKEFILE
		else
			echo KO SI JE M M AFFICHE
		fi
		echo "Encore une"
	done
fi
