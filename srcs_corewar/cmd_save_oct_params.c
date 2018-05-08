/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_save_oct_params.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/06 18:51:18 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/07 10:41:45 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "op.h"

static int	ft_params_is_ind(t_vm *vm, t_proc *processor,
		unsigned int *cpt, int i)
{
	signed	short	ind_value;

	ind_value = 0;
	processor->cmd_save.params_type[i] = 3;
	processor->cmd_save.params_size[i] = 2;
	ind_value = vm_read_2(vm, cal_pc_add(processor->pc, *cpt));
	processor->cmd_save.params[i] = ind_value;
	*cpt = *cpt + 2;
	return (1);
}

static int	ft_params_is_dir_2(t_vm *vm, t_proc *processor,
		unsigned int *cpt, int i)
{
	processor->cmd_save.params_type[i] = 2;
	processor->cmd_save.params_size[i] = 2;
	processor->cmd_save.params[i] = vm_read_2(vm,
			cal_pc_add(processor->pc, *cpt));
	*cpt = *cpt + 2;
	return (1);
}

static int	ft_params_is_dir_4(t_vm *vm, t_proc *processor,
		unsigned int *cpt, int i)
{
	processor->cmd_save.params_type[i] = 2;
	processor->cmd_save.params_size[i] = 4;
	processor->cmd_save.params[i] = vm_read_4(vm,
			cal_pc_add(processor->pc, *cpt));
	*cpt = *cpt + 4;
	return (1);
}

static int	ft_params_is_reg(t_vm *vm, t_proc *processor,
		unsigned int *cpt, int i)
{
	processor->cmd_save.params_type[i] = 1;
	processor->cmd_save.params_size[i] = 1;
	processor->cmd_save.params[i] = vm_read_1(vm,
			cal_pc_add(processor->pc, *cpt));
	*cpt = *cpt + 1;
	return (1);
}

int			ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op)
{
	unsigned	char	tmp;
	int					left;
	unsigned	int		cpt;
	int					i;

	left = 0;
	i = -1;
	cpt = 2;
	if (ft_cmd_save_central_error(vm, processor, op) == 0)
		return (0);
	while (++i < gopt()[op].nb_arg)
	{
		tmp = ft_analyze_code(vm, processor, left);
		if (tmp == REG_CODE)
			ft_params_is_reg(vm, processor, &cpt, i);
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 0)
			ft_params_is_dir_4(vm, processor, &cpt, i);
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 1)
			ft_params_is_dir_2(vm, processor, &cpt, i);
		else if (tmp == IND_CODE)
			ft_params_is_ind(vm, processor, &cpt, i);
		left = left + 2;
	}
	processor->cmd_save.cmd_len = cpt;
	return (1);
}
