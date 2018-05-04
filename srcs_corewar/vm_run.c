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

int		check_end(t_vm *vm)
{
	int i;
	int nb_player_alive;

	nb_player_alive = 0;
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].is_alive && vm->player[i].live == 0)
			vm->player[i].is_alive = 0;
		if (vm->player[i].is_alive && vm->player[i].live > 0)
			nb_player_alive++;
		i++;
	}
	return (nb_player_alive > 1);
}

int		check_nb_live_player(t_vm *vm)
{
	int i;
	int nb_live;

	nb_live = 0;
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].is_alive)
			nb_live += vm->player[i].live;
		i++;
	}
	return (nb_live >= NBR_LIVE);
}

void	vm_run(t_vm *vm)
{
	int		nb_cycle;
	int		cycle_last_check;
	int		cycle_to_check;
	int		nb_no_decr;

	nb_cycle = 0;
	cycle_last_check = nb_cycle;
	cycle_to_check = CYCLE_TO_DIE;
	nb_no_decr = 0;
	while (!vm->d || vm->d_nb >= nb_cycle)
	{
		vm_cycle(vm);
		nb_cycle++;
		if (nb_cycle - cycle_last_check >= cycle_to_check)
		{
			if (check_end(vm))
				break ;
			if (check_nb_live_player(vm) || nb_no_decr >= MAX_CHECKS)
			{
				cycle_to_check -= CYCLE_DELTA;
				nb_no_decr = 0;
			}
		}
	}
	if (vm->d)
		vm_dump_mem(vm);
}