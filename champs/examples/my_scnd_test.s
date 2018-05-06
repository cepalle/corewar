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
st r3, 340               # 67
xor r1, r2, r3          # 73
st r3, 380               # 78
#add r1, r2, r3
#st r3, 42
#sub r1, r2, r3
#st r3, 46
#sti r2, %400, %200
#sti r1, %10, %20
#sti r2, %30, %40
#sti r1, %50, %60
#sti r2, %60, %70
#sti r1, %80, %120
#sti r2, %40, %20
#sti r1, %100, %420
#sti r2, %350, %50
#sti r1, %1320, %222
#sti r2, %442, %2
#sti r1, %10, %1888
