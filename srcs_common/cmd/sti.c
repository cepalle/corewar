/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sti.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:42 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		cmd_sti(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				p1;
	int				p2;
	int				p3;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	p1 = read_param(&vm_proc, 0);
	p2 = read_param(&vm_proc, 1);
	p3 = read_param(&vm_proc, 2);
	if (vm_proc.er)
		return (0);
	vm_write_4(vm, cal_pc_add(vm->process[ipr].pc,
		(p2 + p3) % IDX_MOD), (unsigned int)p1);
	return (1);
}
