.name "AUROLLAN"
.comment "HELL YEAH"

l2:		sti r1,%:live,%1
		and r1,%0,r1

live:	st r1, 400
		zjmp %:live

