#! /bin/sh


# Here there race condition doesn't manifest itself because the file sequence.txt is locked in the critical region

i=1
while [ $i -le 20 ]
do
	if ln sequence.txt sequence.txt.lock
	then
		bash ex2_append.sh #Critical region is in this bash script
		rm sequence.txt.lock
	else
		i=$(($i-1))
	fi
	i=$(($i+1))
done
