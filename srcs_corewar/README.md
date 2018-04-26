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

 |  NOM   |  op  |  oc_param |     ecriture         | ecriture bytecode         | operation                                      |       remarque
--------------------------------------------------------------------------------------------------------------------------------------------------------------------
 |  live  |  01  |     0     | live %X              | 01 (XX-XX-XX-XX)                                 | player_live = live + 1                         |
 |	ld    |  02  |     1     | ld X, rX             | 02 XX (XX *2 ou *4) XX                           | rX = val_param                                 | change le carry
 |	st    |  03  |     1     | st rX, NBR           | 03 XX XX (XX *1 ou *4)                           | adresse = **PC** + (NBR % **IDX_MOD**))        | stock le registre a cette adresse
 |	add   |  04  |     1     | add rX, rX, rX       | 04 XX XX XX XX                                   | param_3 = param_1 + param_2                    | change le carry ensuite
 |	sub   |  05  |     1     | sub rX, rX, rX       | 05 XX XX XX XX                                   | param_3 = param_1 - param_2                    | change le carry
 |	and   |  06  |     1     | and X, X, rX         | 06 XX (XX *1 ou *2 ou *4) (XX *1 ou *2 ou *4) XX | registre = param_1 & param_2                   | change le carry
 |	or    |  07  |     1     | or X, X, rX          | 07 XX (XX *1 ou *2 ou *4) (XX *1 ou *2 ou *4) XX | registre = param_1 | param_2                   | change le carry
 |	xor   |  08  |     1     | xor X, X, rX         | 08 XX (XX *1 ou *2 ou *4) (XX *1 ou *2 ou *4) XX | registre = param_1 ^ param_2                   | change le carry
 |	zjmp  |  09  |     0     | zjmp %X              | 09 (XX-XX)                                       | PC = INDEX                                     | Est ce bien le PC qui pointe desormais un index? fais le jump SI carry == 1
 |	ldi   |  10  |     1     | ldi INDEX, INDEX, rX | 0a XX (XX *1 ou *2 ou *4) (XX *1 ou *2) XX       | adresse = (index + index) taille d'un registre | met le resultat dans param_3 (registre)
**finir verif**
 |	sti   |  11  |     0     | sti rx, var, var     | 0b XX XX  XX-XX XX-XX                            | adresse = (index + index) % (1024*4/8)         | on copie registre a cette adresse
 |	fork  |  12  |     0     | fork INDEX           | 0c (XX-XX)                                       | fork ?  PC = (PC + (1er paramètre % IDX_MOD))  | nouveau processus, qui hérite des différents états de son père
 |	lld   |  13  |
 |	lldi  |  14  |
 |	lfork |  15  |
 |	aff   |  16  |


| Op    | Binaire | Hexa |  Cycle | Arg 1                   | Arg 2                   | Arg 3          | carry | octet_param | dir_size_2 |
| ------|:-------:| :---:| :----: | :---------------------: | :---------------------: | :------------: | :----:| :----------:| :---------:|
| live  | 0000001 | 0x01 | 10     | T_DIR                   |                         |                | 0     | 0           | 0          |
| ld    | 0000010 | 0x02 | 5      | T_DIR or T_IND          | T_REG                   |                | 1     | 1           | 0          |
| st    | 0000011 | 0x03 | 5      | T_REG                   | T_IND or T_REG          |                | 0     | 1           | 0          |
| add   | 0000100 | 0x04 | 10     | T_REG                   | T_REG                   | T_REG          | 1     | 1           | 0          |
| sub   | 0000101 | 0x05 | 10     | T_REG                   | T_REG                   | T_REG          | 1     | 1           | 0          |
| and   | 0000110 | 0x06 | 6      | T_REG or T_DIR or T_IND | T_REG or T_IND or T_DIR | T_REG          | 1     | 1           | 0          |
| or    | 0000111 | 0x07 | 6      | T_REG or T_IND or T_DIR | T_REG or T_IND or T_DIR | T_REG          | 1     | 1           | 0          |
| xor   | 0001000 | 0x08 | 6      | T_REG or T_IND or T_DIR | T_REG or T_IND or T_DIR | T_REG          | 1     | 1           | 0          |
| zjmp  | 0001001 | 0x09 | 20     | T_DIR                   |                         |                | 0     | 0           | 1          |
| ldi   | 0001010 | 0x0a | 25     | T_REG or T_DIR or T_IND | T_DIR or T_REG          | T_REG          | 0     | 1           | 1          |
| sti   | 0001011 | 0x0b | 25     | T_REG                   | T_REG or T_IND or T_DIR | T_DIR or T_REG | 0     | 1           | 1          |
| fork  | 0001100 | 0x0c | 800    | T_DIR                   |                         |                | 0     | 0           | 1          |
| lld   | 0001101 | 0x0d | 10     | T_DIR or T_IND          | T_REG                   |                | 1     | 1           | 0          |
| lldi  | 0001110 | 0x0e | 50     | T_REG or T_DIR or T_IND | T_DIR or T_REG          | T_REG          | 1     | 1           | 1          |
| lfork | 0001111 | 0x0f | 1000   | T_DIR                   |                         |                | 0     | 0           | 1          |
| aff   | 0010000 | 0x10 | 2      | T_REG                   |                         |                | 0     | 1           | 0          |




 AND (ET)
 L'opérateur binaire AND combine l'état de 2 bits selon le tableau suivant :

 Table de vérité AND
 A	B	A AND B
 0	0	0
 0	1	0
 1	0	0
 1	1	1
 L'opérateur C est &. Il agit sur chaque bit de la valeur :

    unsigned a = 0xF0F0;
    unsigned b = 0x00FF;
    unsigned c = a & b; /* c == 0000000011110000 soit 0x00F0 */


 OR (OU)
 L'opérateur binaire OR combine l'état de 2 bits selon le tableau suivant :

 Table de vérité OR
 A	B	A OR B
 0	0	0
 0	1	1
 1	0	1
 1	1	1
 L'opérateur C est |. Il agit sur chaque bit de la valeur :

    unsigned a = 0xF0F0;
    unsigned b = 0x00FF;
    unsigned c = a | b; /* c == 1111 0000 1111 1111 soit 0xF0FF */

 XOR (OU exclusif)
 L'opérateur binaire XOR combine l'état de 2 bits selon le tableau suivant :

 Table de vérité XOR
 A	B	A XOR B
 0	0	0
 0	1	1
 1	0	1
 1	1	0
 L'opérateur C est ^. Il agit sur chaque bit de la valeur :

    unsigned a = 0xF0F0;
    unsigned b = 0x00FF;
    unsigned c = a ^ b; /* c == 1111 0000 0000 1111 soit 0xF00F */
