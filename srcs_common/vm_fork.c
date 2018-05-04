/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:27:46 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:27:56 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

void	vm_fork(t_vm *vm, int ipr, int add)
{
	t_proc to_add;

	to_add = vm->process[ipr];
	to_add.PC = cal_pc_add(to_add.PC, add);
	if (vm->nb_process >= vm->len_process)
	{
		vm->process = ft_realloc(vm->process,
			sizeof(t_proc) * vm->len_process,
			sizeof(t_proc) * vm->len_process * 2);
		vm->len_process *= 2;
	}
	vm->process[vm->nb_process] = to_add;
	vm->nb_process++;
}
