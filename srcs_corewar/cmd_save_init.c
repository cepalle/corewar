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

/*static void 	ft_debug(t_proc *processor, int op)
{
	int i;

	i = 0;
	ft_printf("ft_debug\n");
	while (i < gopt()[op].nb_arg)
	{
		ft_printf("params_type[%d] = %d    params_size[%d] = %d     "
						  "params[%d] = %d   \n",i,
				  processor->cmd_save.params_type[i], i,
				  processor->cmd_save.params_size[i],i ,
				  processor->cmd_save.params[i]);
		i++;
	}
}*/

static int	ft_no_oct_params(t_vm *vm, t_proc *processor, int op)
{
//	ft_printf("ft_no_oct_params\n");
	if (gopt()[op].opcode == 1)
	{
		processor->cmd_save.params_size[0] = 4;
		processor->cmd_save.params[0] =
				(signed int)vm_read_4(vm, cal_pc_add(processor->PC, 1));
		processor->cmd_save.cmd_len = 5;
	}
	else
	{
		processor->cmd_save.params_size[0] = 2;
		processor->cmd_save.params[0] =
				(signed short)vm_read_2(vm, cal_pc_add(processor->PC, 1));
		processor->cmd_save.cmd_len = 3;
	}
	processor->cmd_save.params_type[0] = 2;
	return (1);
}

static	int	ft_get_op_ppichier(t_vm *vm, t_proc *processor)
{
	int i;

	//ft_printf("ft_get_op_ppichier\n");
	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (gopt()[i].opcode == vm->tab[processor->PC])
			return (i);
		i++;
	}
	return (-1);
}

int			stock_cmd(t_vm *vm, t_proc *processor)
{
	int op;

	//ft_printf("stock_cmd\n");
	if ((op = ft_get_op_ppichier(vm, processor)) == -1)
		return (0);
	if (gopt()[op].octet_param == 1)
	{
		ft_analyze_oct_params(vm, processor, op);
		processor->cmd_save.cmd = gopt()[op].op_fct;
	}
	else
	{
		ft_no_oct_params(vm, processor, op);
		processor->cmd_save.cmd = gopt()[op].op_fct;
	}
	processor->cmd_save.cycle_wating = (unsigned int)gopt()[op].cycle;
//	ft_debug(processor, op);
	return (1);
}
