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

int			cmd_live(t_vm *vm, t_proc *proc)
{
	int		er;
	int		p1;

	er = 0;
	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	p1 = get_param(proc, 0, &er);
	if (er)
		return (0);
	player_add_live(vm, p1);
	return (1);
}
