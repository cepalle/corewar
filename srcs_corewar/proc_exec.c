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
#include "op.h"

void	proc_exec(t_vm *vm, int ipr)
{
	char	opcode;

	if (!vm->process[ipr].cmd_save.cmd)
	{
		ft_bzero(&(vm->process[ipr].cmd_save), sizeof(t_cmd_save));
		opcode = vm_read_1(vm, vm->process[ipr].PC);
		if (opcode < 1 || opcode > 16)
		{
			vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC, 1);
			return ;
		}
		else
		{
			vm->process[ipr].cmd_save.cycle_wating = get_op_cmd(opcode).cycle;
			vm->process[ipr].cmd_save.opcode = opcode;
			vm->process[ipr].cmd_save.cmd = get_op_cmd(opcode).op_fct;
		}
	}
	vm->process[ipr].cmd_save.cycle_wating--;
	if (vm->process[ipr].cmd_save.cycle_wating <= 0)
	{
		stock_cmd(vm, vm->process + ipr);
		if (vm->process[ipr].cmd_save.cmd)
			((t_cmd)vm->process[ipr].cmd_save.cmd)(vm, ipr);
		vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
			vm->process[ipr].cmd_save.cmd_len);
		ft_bzero(&(vm->process[ipr].cmd_save), sizeof(t_cmd_save));
	}
}

void	procs_exec(t_vm *vm)
{
	int	i;

	i = vm->nb_process;
	while (i)
	{
		proc_exec(vm, i - 1);
		i--;
	}
}
