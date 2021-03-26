#!/bin/bash
./a.out <public-testcases/$1/source.c ;    
gcc -o out assembly.s ;
./out <public-testcases/$1/input.txt >output.txt;   
diff -bB summary.txt public-testcases/$1/summary.txt;
echo $?
diff -bB output.txt public-testcases/$1/output.txt;
echo $?
cat output.txt
cat summary.txt
