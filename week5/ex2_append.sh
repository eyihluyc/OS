#! /bin/sh

if [ -e sequence.txt ]
then
	touch sequence.txt
fi

#Here critical the region starts:
number=$(tail -n 1 sequence.txt)
echo $((number+1)) >> sequence.txt
