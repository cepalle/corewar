#include "op.h"
#include "corewar.h"
#include "../libft/includes/libft.h"

// il va peut etre falloir lancer une recursive pour chaque processus de chaque joueur ?

void 	ft_st(t_player player, int nbr, int num_reg, t_vm *vm)
{
	int addr;



	addr = vm->tab[player.process->PC] + (nbr % IDX_MOD);
	ft_memcpy(vm->tab + addr, player.process->reg + num_reg, REG_CONTENT_SIZE);
}

void 		ft_run_vm(t_vm *vm)
{

	ft_printf("ft_run_mv\n");
	ft_st(vm->player[0], );
	/*
	int a;
	int nb_checks;
	int MAX_CYCLE;
	int count;

	a = 0;
	count = 0;
	MAX_CYCLE = CYCLE_TO_DIE;
	while (1)
	{
		count++;
		vm->cycle = vm->cycle + 1;
		if (count == MAX_CYCLE)
		{
			count = 0;
			MAX_CYCLE = MAX_CYCLE - CYCLE_DELTA;
		}
		if (nb_live_depuis_der_verif > NBR_LIVE)
			CYCLE_TO_DIE = CYCLE_TO_DIE - CYCLE_DELTA;
		if (MAX_CHECKS == nb_checks)
			CYCLE_TO_DIE = CYCLE_TO_DIE - CYCLE_DELTA;

	}
 */

}
