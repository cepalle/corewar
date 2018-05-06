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

void	vm_run(t_vm *vm)
{
	int		cycle_last_check;
	int		cycle_to_check;
	int		nb_no_decr;

//	ft_printf("vm_run\n");
	vm->cycle = 1;
	cycle_last_check = vm->cycle;
	cycle_to_check = CYCLE_TO_DIE;
	nb_no_decr = 0;
	while (!vm->d || vm->d_nb >= vm->cycle)
	{
		//ft_printf("### CYCLE %d\n", nb_cycle);
		//ft_printf("d_nb %d\n", vm->d_nb);
		vm_cycle(vm);
		vm->cycle++;
		if (vm->cycle - cycle_last_check >= cycle_to_check)
		{
			cycle_last_check = vm->cycle;
			ft_printf("##################################################\n");
			kill_player(vm);
			if (count_player_alive(vm) <= 1)
			{
				ft_printf("end\n");
				return ;
			}
			reset_live(vm);
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
