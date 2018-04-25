.name "kroz"
.comment "EZ tro fassil de win"

l2:	fork %:live	
	sti r1, %:live, %1

live:	live %1
		zjmp %:live
