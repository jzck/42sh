#!/bin/sh
verbose=0
if [ "$1" = "-v" ]
then
	verbose=1
fi
word=$(git status -s | sed 's/.* //')
red="\033[38;5;1m"
gre="\033[38;5;2m"
cya="\033[38;5;6m"
res="\033[0m"

elem_in_array ()
{
	for cur in $2
	do
		if [ "$1" = "$cur" ]
		then
			echo "1"
			return 1
		fi
	done
	echo "0"
	return 0
}

array_in_array ()
{
	for cur in $1
	do
		match=$(elem_in_array "$cur" "$2")
		if [ "$match" -ne 1 ]
		then
			echo "0"
			return 0
		fi
	done
	echo "1"
	return 1
}

confirm ()
{
	echo "$cya${1:-Are you sure? [y/N]}$res"
	read -r -p " " response
	case "$response" in
		[yY][eE][sS]|[yY]) 
			true
			;;
		*)
			false
			;;
	esac
}

do_checkout ()
{
	i_tmp=$(echo $i | sed 's/\//_/g')
	cp $i "$HOME/Documents/.$i_tmp.back"
	git checkout $i
	if [ $verbose -eq 1 ]
	then
		echo "$gre D - O - N - E $res"
		echo "$cya $i was checked out. A copy still exist in $HOME/Documents/.$i_tmp.back$res\n"
	fi
}

if [ $verbose -eq 1 ]
then
	for i in $word
	do
		if [ -e $i ]
		then
			if [ -f $i ]
			then
				diff=$(git diff -U0 --exit-code --color $i)
				if [ "$?" -eq 1 ]
				then
					nb_lines=$(echo "$diff" | wc -l)
					if [ "$nb_lines" -eq 7 ]
					then
						match=$(array_in_array "-9 +9 Updated: by ### ########.fr" "$diff")
						if [ $match -eq 1 ]
						then
							echo "\n$cya CHANGES on $i :$res"
							echo "$diff"
							confirm
							if [ $? -eq 0 ]
							then
								do_checkout
							else
								echo "$cya Nothing done for $i$res\n"
							fi
						else
							echo "$gre$i is not concerned (diff on the good lines)$res"
						fi
					else
						echo "$gre$i is not concerned (diff is too big)$res"
					fi
				else
					echo "$gre$i is not concerned (diff is null)$res"
				fi
			else
				echo "$red$i is not a regular file$res"
			fi
		else
			echo "$red$i doesn't exist$res"
		fi
	done
else
	for i in $word
	do
		if [ -e $i ]
		then
			if [ -f $i ]
			then
				diff=$(git diff -U0 --exit-code --color $i)
				if [ "$?" -eq 1 ]
				then
					nb_lines=$(echo "$diff" | wc -l)
					if [ "$nb_lines" -eq 7 ]
					then
						match=$(array_in_array "-9 +9 Updated: by ### ########.fr" "$diff")
						if [ $match -eq 1 ]
						then
							do_checkout
						fi
					fi
				fi
			fi
		fi
	done
fi
