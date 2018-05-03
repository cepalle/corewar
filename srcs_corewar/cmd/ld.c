/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ld.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:53 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:54 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		ld(t_vm *vm, t_proc *proc)
{
	int *tab;

	tab = vm->player[num_player].process[num_process].params_size;
//	ld prend 2 parametre
//	tab[0] correspond a un registre code sur 1 octet = on recupere direcement la ref du registre
//	tab[2] correspond a la taille du prochain argument code sur 1 ou 2 octet
	ft_memcpy(&vm->player[num_player].process[num_process].reg[tab[0]],
			  &vm->tab[vm->player[num_player].process[num_process].PC], (size_t)tab[1]);
//			  tab[2] % IDX_MOD;
//	est ce qu'il faut faire un swap[2] ou swap[4]?
//	changement de carry? passage de 1 a 0 ou  1 a 1
//	vm->player[num_player].process[num_process].carry = 1;
}
