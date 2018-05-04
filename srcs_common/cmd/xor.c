/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xor.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:56 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:58 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

// TODO carry
int		cmd_xor(t_vm *vm, int ipr)
{
	int 			er;
	int				p1;
	int				p2;
	int				ri;

	(void)vm;
	er = 0;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	p1 = read_param(vm->process + ipr, 0, &er);
	p2 = read_param(vm->process + ipr, 1, &er);
	ri = set_param(vm->process + ipr, 2, &er);
	if (er)
		return (0);
	vm->process[ipr].carry = 1;
	vm->process[ipr].reg[ri] = p1 ^ p2;
	return (1);
}
