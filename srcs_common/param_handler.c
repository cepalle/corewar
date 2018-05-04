/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   param_handler.c                                  .::    .:/ .      .::   */
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
	ft_printf("init_vm_proc\n");
	ft_bzero(vm_proc, sizeof(t_vm_proc));
	vm_proc->vm = vm;
	vm_proc->ipr = ipr;
	vm_proc->idx_mod = idx_mod;
}

int		read_param(t_vm_proc *vm_proc, int ipar)
{
	t_cmd_save cmd_sav;

	ft_printf("read_param\n");
	if (vm_proc->er)
		return (0);
	ft_printf("je fonctionne\n");
	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save; //segfault
	ft_printf("je te jure que c'est ici\n");
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		if (cmd_sav.params[ipar] > 0 &&
			cmd_sav.params[ipar] < 17)
			return (vm_proc->vm->process->reg[cmd_sav.params[ipar]]);
		vm_proc->er = 1;
		return (0);
	}
	if (cmd_sav.params_type[ipar] == IND_CODE)
	{
		if (vm_proc->idx_mod)
			return (vm_read_4(vm_proc->vm,
							cal_pc_add(vm_proc->vm->process[vm_proc->ipr].PC,
										cmd_sav.params[ipar] % IDX_MOD)));
		else
			return (vm_read_4(vm_proc->vm,
							cal_pc_add(vm_proc->vm->process[vm_proc->ipr].PC,
										cmd_sav.params[ipar])));
	}
	return (cmd_sav.params[ipar]);
}

void	load_param(t_vm_proc *vm_proc, int ipar, int data)
{
	t_cmd_save cmd_sav;

	ft_printf("load_param\n");
	if (vm_proc->er)
		return ;
	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		if (cmd_sav.params[ipar] > 0 && cmd_sav.params[ipar] < 17)
			vm_proc->vm->process[vm_proc->ipr].reg[cmd_sav.params[ipar]] = data;
		else
			vm_proc->er = 1;
	}
	else if (cmd_sav.params_type[ipar] == IND_CODE)
	{
		if (vm_proc->idx_mod)
			vm_write_4(vm_proc->vm,
			cal_pc_add(vm_proc->vm->process[vm_proc->ipr].PC,
			cmd_sav.params[ipar] % IDX_MOD), (unsigned int)(data));
		else
			vm_write_4(vm_proc->vm,
					cal_pc_add(vm_proc->vm->process[vm_proc->ipr].PC,
								cmd_sav.params[ipar]),
				(unsigned int)(data));
	}
	vm_proc->er = 1;
}
