for i in src/*/*.c
do
	echo $i | cat -e > file
	cat -e file >> another_file
	cat -e another_file
done

sleep 2
echo
echo "My sample :"
sleep 2
echo
cat sample/for.sh
