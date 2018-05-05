#!/bin/sh

i=1
diff=""
while test $i != $3
    do
    ./bin_ref/corewar $1 $2 -d $i | grep "0x0" > test_ref
    ./corewar $1 $2  -d $i | grep "0x0" > test_my
    diff=`diff test_ref test_my`
    if [ "$diff" != "" ]
    then
        echo "error turn $i";
        echo "$diff";
        break
    fi
    i=$(($i + 1))
done
