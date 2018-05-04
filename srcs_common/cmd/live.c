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

	init_vm_proc(&vm_proc, vm, ipr, 0);
	p1 = read_param(&vm_proc, 0);
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
		vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	player_add_live(vm, p1);
	return (1);
}
