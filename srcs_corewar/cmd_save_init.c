/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_cmd_init.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 17:12:38 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 17:12:43 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "op.h"

unsigned char	ft_analyze_code(t_vm *vm, t_proc *processor, int left)
{
	unsigned char	tmp;

	tmp = (unsigned char)vm_read_1(vm, cal_pc_add(processor->pc, 1));
	tmp = tmp << left;
	tmp = tmp >> 6;
	return (tmp);
}

static int		ft_no_oct_params(t_vm *vm, t_proc *processor, int op)
{
	if (gopt()[op].opcode == 1)
	{
		processor->cmd_save.params_size[0] = 4;
		processor->cmd_save.params[0] =
				vm_read_4(vm, cal_pc_add(processor->pc, 1));
		processor->cmd_save.cmd_len = 5;
	}
	else
	{
		processor->cmd_save.params_size[0] = 2;
		processor->cmd_save.params[0] =
				vm_read_2(vm, cal_pc_add(processor->pc, 1));
		processor->cmd_save.cmd_len = 3;
	}
	processor->cmd_save.params_type[0] = 2;
	return (1);
}

int				stock_cmd(t_vm *vm, t_proc *processor, int op)
{
	if (gopt()[op].octet_param == 1)
		return (ft_analyze_oct_params(vm, processor, op));
	else
		ft_no_oct_params(vm, processor, op);
	return (1);
}
