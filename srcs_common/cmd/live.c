/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   live.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 11:48:51 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 11:48:52 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

static int	player_add_live(t_vm *vm, int id)
{
	unsigned int	idp;
	int				i;

	idp = (unsigned int)id;
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].id == idp)
		{
			vm->player[i].last_live = vm->cycle;
			if (!vm->db && !vm->l)
				ft_printf("Un processus dit que le joueur %s est en vie\n",
			vm->player[i].head.prog_name);
			vm->player[i].nb_live++;
			return (1);
		}
		i++;
	}
	return (0);
}

int			cmd_live(t_vm *vm, int ipr)
{
	t_vm_proc	vm_proc;
	int			p1;

	init_vm_proc(&vm_proc, vm, ipr, 1);
	p1 = read_param(&vm_proc, 0);
	if (vm_proc.er)
		return (0);
	player_add_live(vm, p1);
	vm->process[ipr].nb_live++;
	vm->process[ipr].is_alive = 1;
	return (1);
}
