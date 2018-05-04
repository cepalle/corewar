/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lld.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:17 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:17 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

//lld : Signifie long-load, donc son opcode est évidemment 13.
//C’est la même chose que ld, mais sans % IDX_MOD. Modifie le carry.

int		cmd_lld(t_vm *vm, int ipr)
{
	int		er;
	int		ri;
	int		p;

	er = 0;
	(void)vm;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	p = read_param(vm->process + ipr, 0, &er);
	ri = set_param(vm->process + ipr, 1, &er);
	if (er)
		return (0);
	vm->process[ipr].carry = 1;
	vm->process[ipr].reg[ri] = p;
	return (1);
}
