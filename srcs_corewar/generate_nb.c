/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   generate_nb.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 12:04:48 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 12:04:50 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

static	unsigned	int	ft_check_num_player_input(t_input input,
												int nb)
{
	int b;

	b = -1;
	while (++b < MAX_PLAYERS)
	{
		if ((unsigned int)nb == (unsigned int)input.num_player[b])
			return (0);
	}
	return (1);
}

static	unsigned	int	ft_check_num_player_vm(t_vm *vm, unsigned int a,
													int nb)
{
	unsigned int b;

	b = 0;
	while (b < a)
	{
		if ((unsigned int)nb == vm->player[b].id)
			return (0);
		b++;
	}
	return (1);
}

int						ft_generate_nb(t_vm *vm, t_input input, unsigned int a)
{
	int nb;

	nb = -1;
	while (1)
	{
		if (ft_check_num_player_input(input, nb) == 1
			&& ft_check_num_player_vm(vm, a, nb) == 1)
			return (nb);
		nb--;
	}
}
