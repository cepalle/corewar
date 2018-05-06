/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   live.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:09 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:10 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" // a supprimer une fois debug termine

static void	player_add_live(t_vm *vm, int id)
{
	unsigned int	idp;
	int				i;

	idp = (unsigned int)id;
	i = 0;
	while (i < vm->nb_p)
	{
		if (vm->player[i].id == idp)
		{
			//ft_printf("j'add une vie au cycle = %d\n", vm->cycle);
			vm->player[i].last_live = vm->cycle;
			//ft_printf("last vie du player = %d\n", vm->cycle);
			vm->player[i].live++;
			return ;
		}
		i++;
	}
}

int			cmd_live(t_vm *vm, int ipr)
{
	t_vm_proc	vm_proc;
	int			p1;

	ft_printf("cmd_live\n");
	init_vm_proc(&vm_proc, vm, ipr, 0);
	p1 = read_param(&vm_proc, 0);
	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
		vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	player_add_live(vm, p1);
	return (1);
}
