#!/bin/sh

i=1
diff=""
while test $i != 512
    do
    ./bin_ref/corewar ./champs/examples/my_test.cor ./champs/examples/my_scnd_test.cor -d $i | grep "0x0" > test_ref
    ./corewar ./champs/examples/my_test.cor ./champs/examples/my_scnd_test.cor -d $i | grep "0x0" > test_my
    diff=`diff test_ref test_my`
    if [ "$diff" != "" ]
    then
        echo "error turn $i";
        echo "$diff";
        break
    fi
    i=$(($i + 1))
done
