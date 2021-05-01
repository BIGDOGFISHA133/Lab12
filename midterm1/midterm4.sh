#!/bin/bash

echo Would you like to \(R\)ead, \(A\)dd, \(E\)dit, or \(D\)elete?
read comm
case $comm in
[Rr])
	cat phonebook.txt
	;;
[Aa])
	echo Please enter the phone number:
	read num
	echo Please enter the name:
	read name
	echo Please enter the address:
	read address
	echo $num, $name, $address >> phonebook.txt
	echo The number has been entered.
	;;
[Ee])
	echo Would you like to sort by \(N\)ame, \(A\)ddress, or \(P\)hone number?
	read ed
	case $ed in
		[Nn])
			sort -t, -k 2 phonebook.txt > temp.txt
			cat temp.txt > phonebook.txt
			echo Successfully sorted by name.
			;;
		[Aa])
			sort -t, -k 3n phonebook.txt > temp.txt
			cat temp.txt > phonebook.txt
			echo Successfully sorted by address.
			;;
		[Pp])
			sort -n phonebook.txt > temp.txt
			cat temp.txt > phonebook.txt
			echo Successfully sorted by phone number.
			;;
		*)
			echo invalid entry
			;;
		esac
	;;
[Dd])
	echo Which number, name, or address would you like to delete?
	read del
	sed -i "/\b$del\b/d" phonebook.txt
	;;
*)
	echo invalid entry
	;;
esac
