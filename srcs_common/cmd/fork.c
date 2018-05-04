/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fork.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:47 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:48 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" // a supprimr une fois debug termine

int		cmd_fork(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				p1;

	ft_printf("cmd_fork\n");
	init_vm_proc(&vm_proc, vm, ipr, 0);
	p1 = read_param(&vm_proc, 0);
	if (!vm_proc.er)
		vm_fork(vm, ipr, p1 % IDX_MOD);
	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
									vm->process[ipr].cmd_save.cmd_len);
	return (!vm_proc.er);
}
