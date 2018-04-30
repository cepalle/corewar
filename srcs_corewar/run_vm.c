#include "corewar.h"
#include "op.h"
#include "../libft/includes/libft.h"

static int 	ft_analyze_oct_params(t_vm *vm, int *index, int i)
{
	char *oc_param_binary;
	unsigned int cpt;
	char *octet;

	cpt = 0;
	oc_param_binary = ft_itoa_base(vm->tab[*index],2);
	ft_printf("oct_params_binary = %s\n", oc_param_binary);
	ft_bzero(vm->player->process->params_size, 4);
	while (cpt/2 < gopt()[i].nb_arg)
	{
		octet = ft_strsub(oc_param_binary, cpt, 2);
		if (ft_strcmp(octet, "01") == 0)
			vm->player->process->params_size[cpt/2] = 1;
		if (ft_strcmp(octet, "10") == 0)
			vm->player->process->params_size[cpt/2] = 2;
		if (ft_strcmp(octet, "11") == 0)
			vm->player->process->params_size[cpt/2] = 3;
		free(octet);
		cpt = cpt + 2;
	}
	free(oc_param_binary);
	ft_printf("tab[0] = %d , tab[1] = %d, tab[2]= %d, tab[3] = %d\n", vm->player->process->params_size[0], vm->player->process->params_size[1], vm->player->process->params_size[2], vm->player->process->params_size[3]);
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

void 	ft_run_vm(t_vm *vm, int start)
{
	int cpt;
	int index;

	cpt = start;
	vm->player->process->PC= 0;
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