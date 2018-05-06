/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proc_exec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 09:00:04 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 09:00:05 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

void	proc_exec(t_vm *vm, int ipr)
{
	if (!vm->process[ipr].cmd_save.cmd &&
		!stock_cmd(vm, vm->process + ipr))
	{
		vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC, 1);
		return ;
	}
	vm->process[ipr].cmd_save.cycle_wating--;
	if (vm->process[ipr].cmd_save.cycle_wating <= 0)
	{
		if (vm->process[ipr].cmd_save.cmd)
			((t_cmd)vm->process[ipr].cmd_save.cmd)(vm, ipr);
		vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
			vm->process[ipr].cmd_save.cmd_len);
		ft_bzero(&(vm->process[ipr].cmd_save), sizeof(t_cmd_save));
	}
}
