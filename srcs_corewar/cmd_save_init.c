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

static int 		ft_cmd_save_check_existence(int op, unsigned char tmp, int i)
{
	unsigned char a;

//	ft_printf("ft_cmd_save_check_existence\n");
	a = (unsigned char)gopt()[op].args[i];
	if (tmp == 3)
		tmp = 4;
//	ft_printf("a[%d] = %d  ", i, a);
	if ((a & tmp) != 0)
		return (1);
//	ft_printf("params dans args[%d] non valide", i);
	return (0);
}

static	int 	ft_cmd_save_right_params(t_vm *vm, t_proc *processor, int op)
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
//		ft_printf("tmp_save_right_params[%d] = %d\n", i, tmp);
		i++;
	}
	return (1);
}

static	int 	ft_cmd_save_error_oct_params(t_vm *vm, t_proc *processor)
{
	unsigned char tmp;
	int i;

//	ft_printf("ft_cmd_save_error_oct_params\n");
	i = 0;
	tmp = vm->tab[cal_pc_add(processor->PC, 1)]; // TODO remplacer par cal_PC_add ? // vm->tab[cal_pc_add(process->PC, 1)]
	tmp = tmp << 6;
	if (tmp != 0)
	{
//		ft_printf("erreur : 2 derniers bits non egal a zero = %d \n", tmp);
		return (0);
	}
	return (1);
}


static int 	ft_no_oct_params(t_vm *vm, t_proc *processor, int op) // remplacement de vm_read_x(vm, (vm->process->PC + 1) % MEM_SIZE); par
{
//	ft_printf("ft_no_oct_params\n");
	if (gopt()[op].opcode == 1)
	{
		processor->cmd_save.params_size[0] = 4;
		processor->cmd_save.params[0] = vm_read_4(vm, cal_pc_add(processor->PC, 1));
		processor->cmd_save.cmd_len = 5;
	}
	else
	{
		processor->cmd_save.params_size[0] = 2;
		processor->cmd_save.params[0] = vm_read_2(vm, cal_pc_add(processor->PC, 1));
		processor->cmd_save.cmd_len = 3;
	}
	processor->cmd_save.params_type[0] = 2;
	return (1);
}

static	int		ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op) // remplacement de vm_read_x(vm, (vm->process->PC + cpt) % MEM_SIZE) par vm_read_x(vm, cal_PC_add(vm->process->PC, cpt))
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
	if (ft_cmd_save_error_oct_params(vm, processor) == 0 || ft_cmd_save_right_params(vm, processor, op) == 0)
	{
		processor->cmd_save.cmd_len = (unsigned int)gopt()[op].default_len;
		return (0);
	}
	while (i < gopt()[op].nb_arg)
	{
		tmp = vm->tab[cal_pc_add(processor->PC, 1)]; // TODO remplacer par cal_PC_add ?
		tmp = tmp << left;
		tmp = tmp >> 6;
		if (tmp == REG_CODE)
		{
			processor->cmd_save.params_type[i] = 1;
			processor->cmd_save.params_size[i] = 1;
			processor->cmd_save.params[i] = vm_read_1(vm,
											cal_pc_add(processor->PC, cpt)); //TODO a checker si modulo bien formatte
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
			processor->cmd_save.params_size[i] = 2; 							//TODO a checker si size = 2 ou 4 !!
			ind_value = vm_read_2(vm, cal_pc_add(processor->PC, cpt));
			processor->cmd_save.params[i] = (signed short)ind_value;
			cpt = cpt + 2;
		}
		left = left + 2;
		i++;
	}
	processor->cmd_save.cmd_len = cpt;
	ft_printf("len = %d\n", processor->cmd_save.cmd_len);
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
//		ft_printf("op vaut %d\n", gopt()[op].opcode);   // DEBUG
//		ft_printf("op correspond a %s\n", gopt()[op].name); //DEBUG
		ft_analyze_oct_params(vm, processor, op);
	}
	else
		ft_no_oct_params(vm, processor, op);
	processor->cmd_save.cycle_wating = (unsigned int)gopt()[op].cycle;
	processor->cmd_save.cmd = gopt()[op].op_fct;
//	ft_printf("cycle %d\n", processor->cmd_save.cycle_wating); //DEBUG
//	ft_debug(processor, op);
	return (1);
}
