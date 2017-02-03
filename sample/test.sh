test=10
while [ $test -gt 1 ]
do
	echo hello
	((test--))
done > file1 > file2
