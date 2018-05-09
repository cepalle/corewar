#!/usr/bin/env bash

files=`find champs/championships/2017 -type f -name "*.s" | rev | cut -c3- | rev`;

make

for f1 in $files
do
    for f2 in $files
    do
        for f3 in $files
        do
            echo "$f1 vs $f2 vs $f3"

            ./asm "$f1.s" > /dev/null
            mv "$f1.cor" tmp1.cor
            ./bin_ref/asm "$f1.s" > /dev/null
            mv "$f1.cor" tmp1r.cor

            ./asm "$f2.s" > /dev/null
            mv "$f2.cor" tmp2.cor
            ./bin_ref/asm "$f2.s" > /dev/null
            mv "$f2.cor" tmp2r.cor

            ./asm "$f3.s" > /dev/null
            mv "$f3.cor" tmp3.cor
            ./bin_ref/asm "$f3.s" > /dev/null
            mv "$f3.cor" tmp3r.cor

            ./bin_ref/corewar tmp1r.cor tmp2r.cor tmp3r.cor -d 1200 | grep -a "0x0" > test_ref || true
            ./corewar tmp1.cor tmp2.cor tmp3.cor -dl 1200 | grep -a "0x0" > test_my || true
            rm -f tmp1.cor tmp2.cor tmp3.cor tmp1r.cor tmp2r.cor tmp3r.cor
            diff test_ref test_my
        done
    done
done
