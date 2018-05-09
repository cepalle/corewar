#!/usr/bin/env bash

files=`find champs -type f -name "*.s" | rev | cut -c3- | rev`;

for f1 in $files
do
	for f2 in $files
	do
	echo "$f1 vs $f2"
	`make  diff_corewar CHAMP1=$f1 CHAMP2=$f2 NB_DUMP=12000`

	done
done
