/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   do_op.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/06 15:56:22 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 15:56:23 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		do_op(t_vm *vm, int ipr, t_cal cal)
{
	t_vm_proc		vm_proc;
	int				ri1;
	int				ri2;
	int				res;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	ri1 = read_param(&vm_proc, 0);
	ri2 = read_param(&vm_proc, 1);
	res = cal(ri1, ri2);
	load_param(&vm_proc, 2, res);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = (unsigned char)!res;
	return (1);
}
