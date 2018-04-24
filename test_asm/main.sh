#!/usr/bin/env bash

files=`find champs -type f`;
error=""

for f in $files
do
 echo "Processing $f"
 ./bin_ref/asm $f > /dev/null
 mv `echo $f | sed "s/\.s/\.cor/g"` tmp1.cor
 ./asm $f > /dev/null
 mv `echo $f | sed "s/\.s/\.cor/g"` tmp2.cor
 hexdump -C tmp1.cor > tmp1
 hexdump -C tmp2.cor > tmp2
 error=`diff tmp1 tmp2`
 rm -f tmp1.cor tmp1 tmp2.cor tmp2

 if [ "$error" != "" ]
 then
   echo "error with $f: \n$error\n";
   break
 fi
 error=""
done


