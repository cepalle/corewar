/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cmd_save_check_error.c                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/06 18:47:34 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/06 18:47:36 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"
#include "op.h"

int		ft_cmd_save_add_len_params(t_vm *vm, t_proc *processor, int op)
{
	unsigned char 	tmp;
	int 			i;
	int 			left;

	i = 0;
	left = 0;
	while(i < gopt()[op].nb_arg)
	{
		tmp = vm->tab[cal_pc_add(processor->PC, 1)];
		tmp = tmp << left;
		tmp = tmp >> 6;
		if (tmp == REG_CODE)
			processor->cmd_save.cmd_len += 1;
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 1)
			processor->cmd_save.cmd_len += 2;
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 0)
			processor->cmd_save.cmd_len += 4;
		else if (tmp == IND_CODE)
			processor->cmd_save.cmd_len += 2;
		left = left + 2;
		i++;
	}
	processor->cmd_save.cmd_len += 2;
	return (1);
}

int 	ft_cmd_save_check_existence(int op, unsigned char tmp, int i)
{
	unsigned char a;

//	ft_printf("ft_cmd_save_check_existence\n");
	a = (unsigned char)gopt()[op].args[i];
	if (tmp == 3)
		tmp = 4;
	if ((a & tmp) != 0)
		return (1);
	return (0);
}

int 	ft_cmd_save_right_params(t_vm *vm, t_proc *processor, int op)
{
	unsigned char tmp;
	unsigned char masque;
	int i;
	int right;

//	ft_printf("ft_cmd_save_right_params\n");
	i = 0;
	masque = 0b11000000;
	right = 6;
	while (i < gopt()[op].nb_arg)
	{
		tmp = vm->tab[cal_pc_add(processor->PC, 1)];
		tmp = tmp & masque;
		tmp = tmp >> right;
		masque = masque >> 2;
		right = right - 2;
		if (ft_cmd_save_check_existence(op, tmp, i) == 0)
			return (0);
		i++;
	}
	return (1);
}

int 	ft_cmd_save_error_oct_params(t_vm *vm, t_proc *processor)
{
	unsigned char tmp;
	int i;

//	ft_printf("ft_cmd_save_error_oct_params\n");
	i = 0;
	tmp = vm->tab[cal_pc_add(processor->PC, 1)];
	tmp = tmp << 6;
	if (tmp != 0)
		return (0);
	return (1);
}