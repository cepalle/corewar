/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_save_oct_params.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/06 18:51:18 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 18:51:20 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "op.h"

int		ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op)
{
	unsigned	char	tmp;
	int					left;
	unsigned	int		cpt;
	int					i;
	unsigned	short	ind_value;

	//ft_printf("ft_analyze_oct_params\n");
	left = 0;
	i = 0;
	cpt = 2;
	ind_value = 0;
	if (ft_cmd_save_error_oct_params(vm, processor) == 0 ||
		ft_cmd_save_right_params(vm, processor, op) == 0)
	{
		ft_cmd_save_add_len_params(vm, processor, op);
		return (0);
	}
	while (i < gopt()[op].nb_arg)
	{
		tmp = vm->tab[cal_pc_add(processor->PC, 1)];
		tmp = tmp << left;
		tmp = tmp >> 6;
		if (tmp == REG_CODE)
		{
			processor->cmd_save.params_type[i] = 1;
			processor->cmd_save.params_size[i] = 1;
			processor->cmd_save.params[i] = vm_read_1(vm,
													  cal_pc_add(processor->PC, cpt));
			cpt = cpt + 1;
		}
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 0)
		{
			processor->cmd_save.params_type[i] = 2;
			processor->cmd_save.params_size[i] = 4;
			processor->cmd_save.params[i] = vm_read_4(vm,
													  cal_pc_add(processor->PC, cpt));
			cpt = cpt + 4;
		}
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 1)
		{
			processor->cmd_save.params_type[i] = 2;
			processor->cmd_save.params_size[i] = 2;
			processor->cmd_save.params[i] = vm_read_2(vm,
													  cal_pc_add(processor->PC, cpt));
			cpt = cpt + 2;
		}
		else if (tmp == IND_CODE)
		{
			processor->cmd_save.params_type[i] = 3;
			processor->cmd_save.params_size[i] = 2;
			ind_value = vm_read_2(vm, cal_pc_add(processor->PC, cpt));
			processor->cmd_save.params[i] = (signed short)ind_value;
			cpt = cpt + 2;
		}
		left = left + 2;
		i++;
	}
	processor->cmd_save.cmd_len = cpt;
	return (1);
}