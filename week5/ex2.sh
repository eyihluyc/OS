#! /bin/sh


#Q: How long does it take before race condition manifests itself?
#A: Every time it is different. Mostly, when lauching script 2 times simultanouesly yields either 0 or 1 duplicate numbers


for i in {1..20}
do
	bash ex2_append.sh #Critical region is in this bash script
done
