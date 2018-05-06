/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lfork.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:04 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:05 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" // a suprimer une fois debug termine

int		cmd_lfork(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				p1;

	init_vm_proc(&vm_proc, vm, ipr, 0);
	p1 = read_param(&vm_proc, 0);
	if (!vm_proc.er)
		vm_fork(vm, ipr, p1);
	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
									vm->process[ipr].cmd_save.cmd_len);
	return (!vm_proc.er);
}
