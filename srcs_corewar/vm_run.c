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
	int		nb_cycle = 0;
	int		cycke_last_check = nb_cycle;
	int		cycle_to_check = CYCLE_TO_DIE;
	int		nb_no_decr = 0;

	while (1)
	{
		vm_cycle(vm);
		nb_cycle++;
		if (nb_cycle - cycke_last_check >= cycle_to_check)
		{
			if (check_end(vm))
				break ;
			if (check_nb_live_player(vm) || nb_no_decr >= MAX_CHECKS)
			{
				cycle_to_check -= CYCLE_DELTA;
				if (cycle_to_check <= 0)
					break ;
				nb_no_decr = 0;
			}
		}
		if (vm->d > 0 && nb_cycle >= vm->d)
		{
			vm_print(vm);
			break ;
		}
	}
}
