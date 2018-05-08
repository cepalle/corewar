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

int		cmd_ld(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				p1;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	p1 = read_param(&vm_proc, 0);
	load_param(&vm_proc, 1, p1);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = (unsigned char)!p1;
	return (1);
}
