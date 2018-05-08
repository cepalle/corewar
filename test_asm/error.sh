#!/usr/bin/env bash

files=`find champ_error -type f -name "*.s"`;

for f in $files
do
 echo "Processing $f"
 ./asm $f
done
