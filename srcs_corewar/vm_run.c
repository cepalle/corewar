/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_run.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:51:05 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:51:06 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

int check_end(t_vm *vm)
{
	(void)vm;
	return 0;
}

int check_nb_live_player(t_vm *vm)
{
	(void)vm;
	return 0;
}

void 	vm_run(t_vm *vm)
{
	int		nb_no_decr = 0;
	int		cycle_current = 0;
	int		cycle_to_die = CYCLE_TO_DIE;

	while (1)
	{
		nb_no_decr++;
		cycle_current++;
		vm_cycle(vm);
		if (cycle_current >= cycle_to_die)
		{
			if (check_end(vm))
				break ; // TODO END
			if (check_nb_live_player(vm) || nb_no_decr >= MAX_CHECKS)
			{
				cycle_to_die -= CYCLE_DELTA;
				if (cycle_to_die <= 0)
					break ; // TODO END
				nb_no_decr = 0;
			}
		}
	}
}
