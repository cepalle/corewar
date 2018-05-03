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

/** fct erreur : //Cas d erreur oct params non valide : pas bon argument ou pas assez par ex)  ou si octet final different de 00 **/

static int 	ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op)
{

	unsigned char 	tmp;
	int 			left;
	unsigned int	cpt;
	int				i;

	left = 0;
	i = 0;
	cpt = 1;
	while (i < gopt()[op].nb_arg)
	{
		tmp = processor->cmd_save.codage_param;
		tmp  = tmp << left;
		tmp  = tmp >> 6;
		if (tmp == REG_CODE)
		{
			cpt = cpt + 1;
			processor->cmd_save.params[i] = vm_read_1(vm, vm->process->PC + cpt);
		}
		if (tmp == DIR_CODE)
		{
			cpt = cpt + 4;
			processor->cmd_save.params[i] = vm_read_2(vm, vm->process->PC + cpt);
		}
		if (tmp == IND_CODE)
		{
			cpt = cpt + 2;
			processor->cmd_save.params[i] = vm_read_4(vm, vm->process->PC + cpt);
		}
		left = left + 2;
		i++;
	}
	processor->cmd_save.cmd_len = cpt + 1;
	ft_printf("len = %d\n", processor->cmd_save.cmd_len);
	return (1);
}

static int ft_get_op_ppichier(t_vm *vm, t_proc *processor)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (gopt()[i].opcode == vm->tab[processor->PC])
			return (i);
		i++;
	}
	return (-1);
}

int 		stock_cmd(t_vm *vm, t_proc *processor)
{
	int op;

	if ((op = ft_get_op_ppichier(vm, processor)) == -1)
	{
		ft_printf("op vaut %d\n", op);
		return (0);
	}
	if (gopt()[op].octet_param == 1)
	{
		ft_printf("op vaut %d\n", op);
		ft_printf("op correspond a %s\n", gopt()[op].name);
		processor->cmd_save.codage_param = (vm->tab[processor->PC + 1]);
		ft_analyze_oct_params(vm, processor, op);
	}
	processor->cmd_save.cmd = gopt()[op].op_fct;
	return (1);
}