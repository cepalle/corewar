l2:		fork %:live
		sti r1, %:live, %1

live:	live %1
		zjmp %:live

0c 00 0a 0b 68 01 00 07 00 01 01 00 00 00 01 09 ff fb

  12    00 0a    0b    68      01      00-07     00-01      01   00-00-00-01  09    ff-fb

 [op] [index]   [op]  [ocod]  [reg]   [index]   [valeur]   [op]    [param]   [op]   [index]

 fork    10     sti    1+2+4    1      pc + 7      1       live       1      zjmp   %4096

sti : Opcode 11. Prend un registre, et deux index (potentiellement des registres).
Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée
la valeur du premier paramètre.
index1 + index2 = dist en octet depuis le debut
on reecrit ce que contient le r1 a cette adresse
limite %512 au total => %IDX_MOD soit %1024*4/8
ecriture = "sti r10, %256, %256"

fork : Pas d’octet de codage des paramètres, prend un index, opcode 0x0c. Crée
		un nouveau processus, qui hérite des différents états de son père, à part son PC,
		qui est mis à (PC + (1er paramètre % IDX_MOD)).
	    fork = PC + %5(exemple) % (1024*4/8)



ld : Prend un paramètre quelconque et un registre. Charge la valeur du premier
paramètre dans le registre. Son opcode est 10 en binaire, et il changera le carry
registre = valeur du param
ecriture = "ld %12, r10"
limite de ld 4294967295 (soit code sur 4 octet)

lld : Signifie long-load, donc son opcode est évidemment 13. C’est la même chose
que ld, mais sans % IDX_MOD. Modifie le carry.
