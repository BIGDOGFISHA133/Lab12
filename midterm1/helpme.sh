#!/bin/bash

echo please input a command
read num
case $num in
cd)
	sed -n '1,1671'p mandatabase.txt
	;;
vi)
	sed -n '1672,2109'p mandatabase.txt
	;;
ls)
	sed -n '2110,2363'p mandatabase.txt
	;;
cat)
	sed -n '2364,2442'p mandatabase.txt
	;;
mv)
	sed -n '2443,2548'p mandatabase.txt
	;;
mkdir)
	sed -n '2549,2611'p mandatabase.txt
	;;
wc)
	sed -n '2612,2678'p mandatabase.txt
	;;
rm)
	sed -n '2679,2786'p mandatabase.txt
	;;
cp)
	sed -n '2787,2965'p mandatabase.txt
	;;
head)
	sed -n '2966,3030'p mandatabase.txt
	;;
*)
	echo "sorry, I cannot help you"
	;;
esac

