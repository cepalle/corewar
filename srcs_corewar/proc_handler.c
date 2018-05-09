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
#include "libft.h"

void	sup_proc(t_vm *vm, int ipr)
{
	if (ipr == vm->nb_process - 1)
	{
		vm->nb_process--;
		return ;
	}
	ft_memmove(vm->process + ipr, vm->process + ipr + 1,
		sizeof(t_proc) * (vm->nb_process - ipr - 1));
	vm->nb_process--;
}

void	kill_proc(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (!vm->process[i].is_alive)
		{
			sup_proc(vm, i);
			continue ;
		}
		i++;
	}
}

int		count_nb_live_proc(t_vm *vm)
{
	int i;
	int nb_live;

	nb_live = 0;
	i = 0;
	while (i < vm->nb_process)
	{
		nb_live += vm->process[i].nb_live;
		i++;
	}
	return (nb_live);
}

int		check_nb_live_proc(t_vm *vm)
{
	return (count_nb_live_proc(vm) >= NBR_LIVE);
}

void	reset_live(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->nb_process)
	{
		vm->process[i].nb_live = 0;
		vm->process[i].is_alive = 0;
		i++;
	}
	i = 0;
	while (i < vm->nb_p)
	{
		vm->player[i].nb_live = 0;
		i++;
	}
}
