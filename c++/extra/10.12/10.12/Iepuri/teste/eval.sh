#!/bin/bash
g++ -std=c++0x -o iepuri iepuri4.cpp
for i in `seq 0 9`
do
	echo "Testul $i :"
	time ./iepuri < "iepuri$i.in" > "iepuri.out"
	cat "iepuri$i.ko"
	cat "iepuri.out"
#	diff "iepuri$i.ko" "iepuri.out"
	echo
done
