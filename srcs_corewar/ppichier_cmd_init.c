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

static void 	ft_debug(t_proc *processor, int op)
{
	int i;

	i = 0;
	while (i < gopt()[op].nb_arg)
	{
		ft_printf("params_type[%d] = %d    params_size[%d] = %d     params[%d] = %d   \n",i, processor->cmd_save.params_type[i], i,processor->cmd_save.params_size[i],i , processor->cmd_save.params[i]);
		i++;
	}
}

/*static	int ft_cmd_save_check_error(t_vm *vm, t_proc *processor, int op)
{
fct erreur : //Cas d erreur oct params non valide : pas bon argument ou pas assez par ex)  ou si octet final different de 00
}*/

static int 	ft_no_oct_params(t_vm *vm, t_proc *processor, int op)
{
	if (gopt()[op].opcode == 1)
	{
		processor->cmd_save.params_size[0] = 4;
		processor->cmd_save.params[0] = vm_read_4(vm, (vm->process->PC + 1) % MEM_SIZE);
	}
	else
	{
		processor->cmd_save.params_size[0] = 2;
		processor->cmd_save.params[0] = vm_read_2(vm, (vm->process->PC + 1) % MEM_SIZE);
	}
	processor->cmd_save.params_type[0] = 2;
	return (1);
}

static int 	ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op)
{

	unsigned char 	tmp;
	int 			left;
	unsigned int	cpt;
	int				i;
	unsigned int 	ind_value;

	left = 0;
	i = 0;
	cpt = 2;
	ind_value = 0;
	while (i < gopt()[op].nb_arg)
	{
		tmp = vm->tab[(processor->PC + 1) % MEM_SIZE];
		tmp  = tmp << left;
		tmp  = tmp >> 6;
		if (tmp == REG_CODE)
		{
			processor->cmd_save.params_type[i] = 1;
			processor->cmd_save.params_size[i] = 1;
			processor->cmd_save.params[i] = vm_read_1(vm, (vm->process->PC + cpt) % MEM_SIZE);
			cpt = cpt + 1;
		}
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 0)
		{
			processor->cmd_save.params_type[i] = 2;
			processor->cmd_save.params_size[i] = 4;
			processor->cmd_save.params[i] = vm_read_4(vm, (vm->process->PC + cpt) % MEM_SIZE);
			cpt = cpt + 4;
		}
		else if (tmp == DIR_CODE && gopt()[op].dir_size_2 == 1)
		{
			processor->cmd_save.params_type[i] = 2;
			processor->cmd_save.params_size[i] = 2;
			processor->cmd_save.params[i] = vm_read_2(vm, (vm->process->PC + cpt) % MEM_SIZE);
			cpt = cpt + 2;
		}
		else if (tmp == IND_CODE)
		{
			processor->cmd_save.params_type[i] = 3;
			processor->cmd_save.params_size[i] = 2; //TODO a checker si size = 2 ou 4 !!
			ind_value = vm_read_2(vm, (vm->process->PC + cpt) % MEM_SIZE);
			processor->cmd_save.params[i] = vm_read_4(vm, (vm->process->PC + ind_value) % MEM_SIZE);
			cpt = cpt + 2;
		}
		left = left + 2;
		i++;
	}
	processor->cmd_save.cmd_len = cpt ;
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
		return (0);
	if (gopt()[op].octet_param == 1)
	{
		ft_printf("op vaut %d\n", gopt()[op].opcode);   // DEBUG
		ft_printf("op correspond a %s\n", gopt()[op].name); //DEBUG
		ft_analyze_oct_params(vm, processor, op);
	}
	else
		ft_no_oct_params(vm, processor, op);
	processor->cmd_save.cycle_wating = (unsigned int)gopt()[op].cycle;
	processor->cmd_save.cmd = gopt()[op].op_fct;
	ft_printf("cycle %d\n", processor->cmd_save.cycle_wating); //DEBUG
	ft_debug(processor, op);
	return (1);
}