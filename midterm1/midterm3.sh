#!/bin/bash
echo Enter a number: 
read num

date -d "now - $num days"


find . -iname "*" -atime +$num -type f -ls

echo $num

