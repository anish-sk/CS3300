#!/bin/bash
# script for individual submission evaluation

LAB="A2"

# Change this
BASE_FOLDER=temp

# must contain all testcases and outputfiles
# test cases must be named as input([0-9]+) and correspondings outputs as output([0-9]+)
#TEST_CASES_DIR=$BASE_FOLDER/$LAB/testcases
TEST_CASES_DIR=../../testcases

# submission folder must contain all submissions downloaded from moodle, should follow the filename convention, else rename manually
SUB_DIR=$BASE_FOLDER/$LAB/submissions

# contains result files of individual students with score in the end. Named after the roll number. 
RESULT_DIR=$BASE_FOLDER/$LAB/results

mkdir -p $RESULT_DIR

RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[0;32m'

if [ $# -lt 1 ]
then
	echo "usage: ./eval.sh <ROLL NUMBER>"
	exit
fi

# argument to the script should be the roll number in CSXXBXXX format.
ROLL_NO=$1

echo "--> Evaluating ${ROLL_NO}"
echo "-------------------------"

# temp directory for extracting the files, NOTE: /tmp gets cleaned after restart
#SRC_TEMP_DIR=/tmp/$LAB/
#mkdir -p ${SRC_TEMP_DIR}

#remove (if)any previous evaluation files
#rm -rf ${SRC_TEMP_DIR}/${ROLL_NO}
#Doesn't recognize the format
#tar -xzf ${SUB_DIR}/${ROLL_NO}.tar.gz -C $SRC_TEMP_DIR
#recognizes the .xz .gz. .tar formats
#tar xf ${SUB_DIR}/${ROLL_NO}.tar.gz -C $SRC_TEMP_DIR 
#tar xf ${SUB_DIR}/${ROLL_NO}.* -C $SRC_TEMP_DIR 
#if [ $? -ne 0 ]
#then
    #echo -e "${RED}Failed to unarchive files${NC}"
    #exit
#fi
make > /dev/null
#cd ${SRC_TEMP_DIR}/${ROLL_NO}
cd $SUB_DIR/$ROLL_NO
rm -f a.out *.tab.* lex.yy.c
make > /dev/null
if [ ! -f a.out ]; then 
	echo -e "${RED}Make failed!${NC}"
	exit
fi
echo "Make Successful"
#cd - > /dev/null
#exit

# Execute testcases
marks=0

echo "$ROLL_NO:" >> result
count=0
var = 0
# output file for students
mkdir -p output
# make sure only testcase files are present in TEST_CASES_DIR
#echo $TEST_CASES_DIR
#pwd
for testcase in $(ls $TEST_CASES_DIR/input*)
do
    ((var++))
    #echo $testcase
    fname=`echo "$testcase" | sed "s/.*\///"`
    no=$(echo "$fname" | grep -o -E [0-9]+)
    #echo $no
    ofile="output$no"
    taofile="${TEST_CASES_DIR}/output$no"
    ./a.out < $testcase > output/$ofile 2>/dev/null
    #./a.out < $testcase 2&1 > output/$ofile
    paste output/$ofile $taofile
    val=$(diff -w output/$ofile $taofile | wc -l)

    # no partial marks for any testcases
    if [ $val -eq 0 ]
    then
        #if [ $no -ge 15 ] || [ $no -le 4 ]; then
            count=$(echo "${count} + 1" | bc -l)
        #else
        #    count=$(echo "${count} + 2" | bc -l)
        #fi
        echo -e "testcase $no: passed" >> result
        echo -e "testcase $no: ${GREEN}passed${NC}"
    else
        echo -e "testcase $no: failed" >> result
        echo -e "testcase $no: ${RED}failed${NC}"
    fi
done 

marks=$(echo "$count / 2.0" | bc -l)
echo "Marks: $count / $var" 
echo "Marks: $marks" >> result

# copy the result file, only thing that matter to us, for uploading scores
#cp result $RESULT_DIR/$ROLL_NO 

# go back to script folder
cd - > /dev/null

