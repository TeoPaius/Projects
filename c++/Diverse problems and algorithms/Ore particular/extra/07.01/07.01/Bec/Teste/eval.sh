#!/bin/bash
g++ -std=c++0x -o arce tree_ok5.cpp
for i in  0 1 2 3 4 5 6 7 8 9   # la fel e asa:   `seq 0 9`
do
	echo "Testul $i:"
	time ./arce < "$i-TREE.IN" > "tree.out"
	cat "$i-TREE.OK"
	cat "tree.out"
	echo
done
