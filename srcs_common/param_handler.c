/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   read_param.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:38:10 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 15:38:11 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

void	init_vm_proc(t_vm_proc *vm_proc, t_vm *vm, int ipr, int idx_mod)
{
	ft_bzero(vm_proc, sizeof(t_vm_proc));
	vm_proc->vm = vm;
	vm_proc->ipr = ipr;
	vm_proc->idx_mod = idx_mod;
}

int		read_param(t_vm_proc *vm_proc, int ipar)
{
	t_cmd_save cmd_sav;

	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		if (cmd_sav.params[ipar] > 0 &&
			cmd_sav.params[ipar] < 17)
			return vm_proc->vm->process->reg[cmd_sav.params[ipar]];
		vm_proc->er = 1;
		return (0);
	}
	if (cmd_sav.params_type[ipar] == IND_CODE)
	{
		if (vm_proc->idx_mod)
			return (vm_read_4(vm_proc->vm,
			cal_PC_add(vm_proc->vm->process[vm_proc->ipr].PC,
			cmd_sav.params[ipar] % IDX_MOD)));
		else
			return (vm_read_4(vm_proc->vm,
			cal_PC_add(vm_proc->vm->process[vm_proc->ipr].PC,
			cmd_sav.params[ipar])));
	}
	return (cmd_sav.params[ipar]);
}

void	set_param(t_vm_proc *vm_proc, int ipar, int data)
{
	t_cmd_save cmd_sav;

	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		*er = 1;
		return (0);
	}

	else if ()
	{

	}
	vm_proc->er = 1;
	return (0);
}
