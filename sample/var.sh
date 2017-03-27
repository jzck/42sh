HELLO=WORLD HELLO=SALUT HELLO="BUENOS DIAS"
echo $HELLO
SALUT=$HELLO
echo $SALUT

sleep 2
echo
echo "My sample :"
sleep 2
echo
cat sample/var.sh
