#!/bin/bash
g++ -std=c++0x -o aut autostrazi3.cpp
for i in `seq 0 9`
do
	echo "Testul $i :"
	time ./aut < "$i-autostrazi.in" > "auto.out"
	cat "$i-autostrazi.ok"
	cat "auto.out"
#	diff "iepuri$i.ko" "iepuri.out"
	echo
done
