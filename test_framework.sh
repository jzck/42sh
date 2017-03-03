SHELL=$1
TOTAL_TEST=0
NBR_TEST_SUCCESS=0
unset LIST_TEST
LIST_TEST='./TESTSHELL/*'/'*'.test
DIR_TEST=./TESTSHELL

do_test() {

for TEST in $LIST_TEST
do

	($SHELL < $TEST 1> ${DIR_TEST}/stdin_test 2> ${DIR_TEST}/stderr_test)
	(bash < $TEST 1> ${DIR_TEST}/stdin_ref 2> ${DIR_TEST}/stderr_ref)

	if ! diff ${DIR_TEST}/stdin_test ${DIR_TEST}/stdin_ref > /dev/null || 
	 ! diff ${DIR_TEST}/stderr_test ${DIR_TEST}/stderr_test > /dev/null	
	then
		echo "\033[0;31mFAILURE $TEST" >> ${DIR_TEST}/resultat
	else
		((NBR_TEST_SUCCESS++))
	fi
	((TOTAL_TEST++))
done
}

do_test

if [ -e ${DIR_TEST}/resultat ]
then 
	cat ${DIR_TEST}/resultat 
fi
echo "\033[0;32mYou succeed $NBR_TEST_SUCCESS tests on $TOTAL_TEST"

rm -f $DIR_TEST/resultat

#add random input sed -n $RANDOM "p" /usr/share/dict/words
#add timeout
#charging phase of test
#real verification of references
#to add extranous comportement
