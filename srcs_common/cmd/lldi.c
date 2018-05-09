/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lldi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:21 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:21 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		cmd_lldi(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				ri1;
	int				ri2;
	int				res;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	ri1 = read_param(&vm_proc, 0);
	ri2 = read_param(&vm_proc, 1);
	res = vm_read_4(vm, cal_pc_add(vm->process[ipr].pc, ri1 + ri2));
	load_param(&vm_proc, 2, res);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = (unsigned char)!res;
	return (1);
}
