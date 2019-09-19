#!/bin/bash
cnt=0
touch ex2.txt
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

