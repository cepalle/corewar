/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:31 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

// TODO carry
int		cmd_add(t_vm *vm, int ipr)
{
	int		er;
	int		ri1;
	int		ri2;
	int		ri3;

	er = 0;
	(void)vm;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
					vm->process[ipr].cmd_save.cmd_len);
	ri1 = set_param(vm->process + ipr, 0, &er);
	ri2 = set_param(vm->process + ipr, 1, &er);
	ri3 = set_param(vm->process + ipr, 2, &er);
	if (er)
		return (0);
	vm->process[ipr].reg[ri3] = vm->process[ipr].reg[ri1] + vm->process[ipr].reg[ri2];
	return (1);
}
