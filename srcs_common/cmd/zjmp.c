/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   zjmp.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 12:09:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 12:09:50 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		cmd_zjmp(t_vm *vm, int ipr)
{
	t_vm_proc	vm_proc;
	int			p1;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	p1 = read_param(&vm_proc, 0);
	if (vm_proc.er || !vm->process[ipr].carry)
		return (0);
	vm->process[ipr].pc = cal_pc_add(vm->process[ipr].pc,
		(p1 % IDX_MOD) - vm->process[ipr].cmd_save.cmd_len);
	return (1);
}
