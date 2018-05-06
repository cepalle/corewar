.name "AUROLLAN"
.comment "HELL YEAH"


l2:		sti r1,%:l3,%1

l3:		ld %200, r1

live:	live %1
   		zjmp %:live
