#!/bin/bash

echo "debut script"

VALUE=3
while [ $VALUE -gt 1 ] 
do 
	sleep 1
	((VALUE--))
	echo "a"
done > file1 | cat ; ls 

ls -l > file2 | cat

echo "fin script"
