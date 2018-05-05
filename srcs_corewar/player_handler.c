/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   player_handler.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/05 16:17:28 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/05 16:17:29 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	kill_player(t_vm *vm)
{
	int i;

//	ft_printf("check_end\n");
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].live == 0)
			vm->player[i].is_alive = 0;
		i++;
	}
}

int		count_player_alive(t_vm *vm)
{
	int i;
	int nb_player_alive;

	nb_player_alive = 0;
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].is_alive)
			nb_player_alive++;
		i++;
	}
	return (nb_player_alive);
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

void reset_live(t_vm *vm)
{
	int i;

//	ft_printf("check_nb_live_player\n");
	i = 0;
	while (i < vm->nb_p)
	{
		vm->player[i].live = 0;
		i++;
	}
}
