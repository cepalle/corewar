/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   st.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:36 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	st(t_vm *vm, t_proc *proc)
{
	int addr;
	int *tab;

	tab = vm->player[num_player].process[num_process].params_size;

	addr = vm->tab[vm->[num_player].process[num_process]->PC] + (tab[1] % IDX_MOD);
	ft_memcpy(vm->tab + addr, &vm->[num_player].process[num_process].reg[tab[0]], REG_CONTENT_SIZE);
//	est ce qu'il faut faire un swap[2] ou swap[4]?
// 	changement de carry? passage de 1 a 0 ou  1 a 1
//	vm->player[num_player].process[num_process].carry = 1;
}

