/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_fork.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:27:46 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 08:32:10 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

void	vm_fork(t_vm *vm, int ipr, int add)
{
	t_proc to_add;

	to_add = vm->process[ipr];
	to_add.pc = cal_pc_add(to_add.pc, add);
	ft_bzero(&(to_add.cmd_save), sizeof(t_cmd_save));
	to_add.nb_live = 0;
	to_add.id = vm->next_id_proc;
	vm->next_id_proc++;
	if (vm->nb_process >= vm->len_process)
	{
		vm->process = ft_realloc(vm->process,
			sizeof(t_proc) * vm->len_process,
			sizeof(t_proc) * vm->len_process * 2);
		vm->len_process *= 2;
		if (!vm->process)
		{
			ft_printf("Anti games detected, you try to kill the vm!\n");
			vm_free(vm);
			exit(1);
		}
	}
	vm->process[vm->nb_process] = to_add;
	vm->nb_process++;
}
