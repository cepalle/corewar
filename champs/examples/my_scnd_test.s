.name "my_test"
.comment "C EST MON TEST"

ld %-1, r1       # 5
ld %642687426, r2            # 10
ld %-3, r3            # 15
st r1, 25               # 20
sti r1, %25, %25        # 45
and r1, r2, r3          # 51
st r3, 300               # 56
or r1, r2, r3           # 62 #
st r3, 24660               # 67
xor r1, r2, r3          # 73
st r3, 380               # 78
#add r1, r2, r3
#st r3, 42
#sub r1, r2, r3
#st r3, 46
