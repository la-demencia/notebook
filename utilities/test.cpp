#!/bin/bash
VAR1=1;
VAR2=1;
while [[ $VAR1 = $VAR2 ]] 
do
	./gen.exe > in4 #gen generates the test, in4 just stores the test
	VAR1=$(./f.exe < in4) #your solution
	VAR2=$(./brute.exe < in4) #brute force solution
	if [[ $VAR1 = $VAR2 ]] 
	then 
		echo "OK"
	fi
done
echo "Wrong Answer, test case:"
cat in4
echo "Answer: " $VAR2
echo "Output: " $VAR1
