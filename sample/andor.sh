pwd > file && pwd >> file || ls | cat && ls | cat >> file || ls
cat -e file 

sleep 2
echo
echo "My script:"
echo
cat sample/andor.sh
