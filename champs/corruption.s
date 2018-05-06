.name "AUROLLAN"
.comment "HELL YEAH"


l2:		sti r1,%:l3,%1

l3:		and  %23, %13, r2

live:	live %1
   		zjmp %:live
