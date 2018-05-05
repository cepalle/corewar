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
#include "libft.h" // a supprimer une fois debug termine

int		check_end(t_vm *vm)
{
	int i;
	int nb_player_alive;

//	ft_printf("check_end\n");
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

//	ft_printf("check_nb_live_player\n");
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

//	ft_printf("vm_run\n");
	nb_cycle = 1;
	cycle_last_check = nb_cycle;
	cycle_to_check = CYCLE_TO_DIE;
	nb_no_decr = 0;
	while (!vm->d || vm->d_nb >= nb_cycle)
	{
		//ft_printf("### CYCLE %d\n", nb_cycle);
		//ft_printf("d_nb %d\n", vm->d_nb);
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
