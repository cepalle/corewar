/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display_win.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/07 14:48:34 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/22 08:40:22 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

static	void	ft_find_last_live(t_vm *vm)
{
	int a;
	int max;

	a = 0;
	max = vm->player[0].last_live;
	while (a + 1 < vm->nb_p)
	{
		if (vm->player[a].last_live < vm->player[a + 1].last_live)
			max = vm->player[a + 1].last_live;
		a++;
	}
	a = 0;
	while (a < vm->nb_p)
	{
		if (max == vm->player[a].last_live)
		{
			ft_printf("Contestant %d(%s) has won !\n",
					vm->player[a].id, vm->player[a].head.prog_name);
			return ;
		}
		a++;
	}
}

void			vm_display_res(t_vm *vm)
{
	if (vm->d && vm->cycle >= vm->d_nb)
	{
		if (vm->db)
			vm_print(vm);
		else
			vm_dump_mem(vm);
		return ;
	}
	ft_find_last_live(vm);
}
