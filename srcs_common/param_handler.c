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

void		init_vm_proc(t_vm_proc *vm_proc, t_vm *vm, int ipr, int idx_mod)
{
	ft_bzero(vm_proc, sizeof(t_vm_proc));
	vm_proc->vm = vm;
	vm_proc->ipr = ipr;
	vm_proc->idx_mod = idx_mod;
}

static int	read_ind(t_vm_proc *vm_proc, int ipar)
{
	t_cmd_save cmd_sav;

	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	if (vm_proc->idx_mod)
		return (vm_read_4(vm_proc->vm,
			cal_pc_add(vm_proc->vm->process[vm_proc->ipr].pc,
			cmd_sav.params[ipar] % IDX_MOD)));
	else
		return (vm_read_4(vm_proc->vm,
			cal_pc_add(vm_proc->vm->process[vm_proc->ipr].pc,
			cmd_sav.params[ipar])));
}

int			read_param(t_vm_proc *vm_proc, int ipar)
{
	t_cmd_save	cmd_sav;
	t_proc		*proc;

	if (vm_proc->er)
		return (0);
	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	proc = vm_proc->vm->process + vm_proc->ipr;
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		if (cmd_sav.params[ipar] > 0 &&
			cmd_sav.params[ipar] < 17)
			return (proc->reg[cmd_sav.params[ipar] - 1]);
		vm_proc->er = 1;
		return (0);
	}
	if (cmd_sav.params_type[ipar] == IND_CODE)
		return (read_ind(vm_proc, ipar));
	else
	{
		return (cmd_sav.params[ipar]);
	}
}

static void	write_ind(t_vm_proc *vm_proc, int ipar, int data)
{
	t_cmd_save cmd_sav;

	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	if (vm_proc->idx_mod)
	{
		vm_write_4(vm_proc->vm,
			cal_pc_add(vm_proc->vm->process[vm_proc->ipr].pc,
			cmd_sav.params[ipar] % IDX_MOD),
			(unsigned int)(data));
	}
	else
		vm_write_4(vm_proc->vm,
			cal_pc_add(vm_proc->vm->process[vm_proc->ipr].pc,
			cmd_sav.params[ipar]),
			(unsigned int)(data));
}

void		load_param(t_vm_proc *vm_proc, int ipar, int data)
{
	t_cmd_save	cmd_sav;
	t_proc		*proc;

	if (vm_proc->er)
		return ;
	cmd_sav = vm_proc->vm->process[vm_proc->ipr].cmd_save;
	proc = vm_proc->vm->process + vm_proc->ipr;
	if (cmd_sav.params_type[ipar] == REG_CODE)
	{
		if (cmd_sav.params[ipar] > 0 && cmd_sav.params[ipar] < 17)
			proc->reg[cmd_sav.params[ipar] - 1] = data;
		else
			vm_proc->er = 1;
	}
	else if (cmd_sav.params_type[ipar] == IND_CODE)
		write_ind(vm_proc, ipar, data);
	else
		vm_proc->er = 1;
}
