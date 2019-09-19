#!/bin/bash
#sum=0
#sum=$((sum+1))
#echo $sum
#for i in $string;
#do
#	echo "$i\n"
#done
#echo $sum
cnt=0
while :
do
	if [ $cnt -eq 1000 ];
	then
		break
	fi
	ln ex2.txt ex2.txt.lock
	cnt=$((cnt+1))
	cur=$(tail -n 1 ex2.txt)
	cur=$((cur+1))
	echo $cur >> ex2.txt
	rm ex2.txt.lock
done

