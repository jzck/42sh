case toto in
	( tutu ) echo PERDU ;;
	( titi ) echo PERDU  ;;
	( toto ) case lala in
					( lolo ) echo PERDU ;;
					( lala ) echo GAGNE ;;
				esac ;;
esac > file
cat -e file

sleep 2
echo
echo "My sample :"
sleep 2
echo
cat sample/case.sh
