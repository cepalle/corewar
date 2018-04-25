.name "kroz"
.comment "EZ tro fassil de win"

fork	%:live
ldi             %:live, r2, r4

live:	live %1
		zjmp %:live
