/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   run_vm.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <ppichier@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 19:06:23 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 19:06:23 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "../libft/includes/libft.h"

/*
int cycle_current = 0;
int nb_check_no_decr = 0;
int cycle_last_check_die = 0;
int cycle_to_die = CYCLE_TO_DIE;

while (1)
{
	nb_check_no_decr++;
	cycle_last_check_die++;
	ft_vm_cycle(vm);
	if (cycle_last_check_die >=  cycle_to_die
		&& !check_end(vm))
	{
		// TODO END
	}
 	else if (cycle_last_check_die >=  cycle_to_die
 		&& (check_nb_live_player(vm) ||
 		nb_check_no_decr + 1 >= MAX_CHECKS))
	{
		cycle_to_die -= CYCLE_DELTA;
		cycle_to_die = ft_max(0, cycle_to_die);
		if cycle_to_die == 0 -> END
		nb_check_no_decr = 0;
	}
}
*/


static int 	ft_analyze_oct_params(t_vm *vm, int *index, int i)
{
	char	*oc_param_binary;
	int		cpt;
	char	*octet;

	cpt = 0;
	oc_param_binary = ft_itoa_base(vm->tab[*index],2);
	ft_printf("oct_params_binary = %s\n", oc_param_binary);
	ft_bzero(vm->player->process->params_size, 3);

	while (cpt/2 < gopt()[i].nb_arg)
	{
		octet = ft_strsub(oc_param_binary, cpt, 2);
		if (ft_strcmp(octet, "01") == 0)
			vm->player->process->params_size[cpt/2] = 1;
		if (ft_strcmp(octet, "10") == 0)
			vm->player->process->params_size[cpt/2] = 4;
		if (ft_strcmp(octet, "11") == 0)
			vm->player->process->params_size[cpt/2] = 2;
		free(octet);
		cpt = cpt + 2;
	}
	free(oc_param_binary);
	ft_printf("tab[0] = %d , tab[1] = %d, tab[2]= %d, tab[3] = %d\n", vm->player->process->params_size[0], vm->player->process->params_size[1], vm->player->process->params_size[2]);
	*index = vm->player->process->params_size[0] + vm->player->process->params_size[1] + vm->player->process->params_size[2];

	return (1);
}*/

static int 	ft_analyze_oct_params(t_vm *vm, int *index, int i)
{
	int cpt;
	int left;
	short tmp;
	short tmp_dec;

	cpt = 0;
	left = 0;
	ft_bzero(vm->player->process->params_size, 3);
	while (cpt < gopt()[i].nb_arg)
	{
		tmp = vm->tab[*index];
		ft_printf("mon tmp = %x\n", vm->tab[*index]);
		tmp_dec = tmp << left;
		tmp_dec = tmp_dec >> 6;
		ft_printf("mon tmp_dec = %d\n", tmp_dec);
		if (tmp_dec == 2)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 4;
		}
		if (tmp_dec == 1)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 1;
		}
		if (tmp_dec == 3)
		{
			ft_printf("mon stock vaut 2\n");
			vm->player->process->params_size[cpt] = 2;
		}
		cpt++;
		left = left + 2;
	}
	ft_printf("cpt = %d\n", cpt);
	ft_printf("tab[0] = %d , tab[1] = %d, tab[2]= %d\n", vm->player->process->params_size[0], vm->player->process->params_size[1], vm->player->process->params_size[2]);
	//*index = vm->player->process->params_size[0] + vm->player->process->params_size[1] + vm->player->process->params_size[2];
	return (1);
}


static int ft_calculate_next_index(t_vm *vm, int *index, int i)
{
	if (gopt()[i].octet_param == 1)
	{
		*index = *index + 1;
		ft_analyze_oct_params(vm, index, i);
	}
	return (1);
}

static int ft_get_op_ppichier(t_vm *vm, int opcode, int *index)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (gopt()[i].opcode == opcode)
		{
			ft_printf("j ai trouve and a l index %d ", *index);
			ft_printf("nom de l op : %s\n", gopt()[i].name);
			ft_printf("opcode : %x\n", gopt()[i].opcode);
			ft_calculate_next_index(vm, index, i);
			//return (gopt()[i].);
			return (1);
		}
		i++;
	}
	return (0);
}

void 	ft_choose_cmd(t_vm *vm, int num_player, int num_process)
{
	while()
	{
		if ()
		{
			t_cmd(vm, num_player, num_process);
		}
	}
	// nothing avencer
}

void 	ft_run_vm(t_vm *vm, int start)
{
	int cpt;
	int index;


	cpt = start;
	vm->player->process = malloc(sizeof(int)); // TODO malloc selon nbr de processus
	vm->player->process->PC = 0;
	index = vm->player->process->PC;
	while (index < MEM_SIZE)
	{
		if (ft_get_op_ppichier(vm, vm->tab[index], &index) == 1)
		{
			ft_printf("index = %d", index);
			return;
		}
		index++;
	}
}
