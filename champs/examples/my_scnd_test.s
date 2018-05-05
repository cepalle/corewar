.name "my_test"
.comment "C EST MON TEST"

ld %888888888, r1            # 5  5
ld %5555, r2            # 5  5
ld %7777, r3            # 5  5
st r1, 25               # 5  10
sti r1, %25, %25        # 25 35
and r1, r2, r3
st r3, 30
or r1, r2, r3
st r3, 34
xor r1, r2, r3
st r3, 38
#add r1, r2, r3
#st r3, 42
#sub r1, r2, r3
#st r3, 46

