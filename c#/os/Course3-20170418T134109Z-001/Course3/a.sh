#!/bin/bash

if [ $# -lt 15 ]; then
	echo Not enough parameters >&2
	exit 1
fi

shift 2

K=0
while [  $K -lt 3 ]; do
	if [ ! -d $1 ]; then
		echo Not a directory >&2
		exit 1

	elif [ ! -f $2 ]; then
                echo Not a file >&2
                exit 1

	elif ! echo $3 | grep -q "^[0-9]\+$"; then
                echo Not a integer >&2
                exit 1
	
	elif ! echo $4 | grep -q -i "^[a-z]\+$"; then
                echo Not a text >&2
                exit 1
        
	fi
	K=`expr $K+1`
	shift 4
done
