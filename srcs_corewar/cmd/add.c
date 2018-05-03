/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   add.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:31 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

static int	check_params(const int	*params)
{
	return (!(params[0] <= 0 || params[0] >= REG_NUMBER ||
			params[1] <= 0 || params[1] >= REG_NUMBER ||
			params[2] <= 0 || params[2] >= REG_NUMBER));
}

int		cmd_add(t_vm *vm, t_proc *proc)
{
	int		r1;
	int		r2;
	int		r3;

	proc->PC += proc->cmd_save.cmd_len;
	if (!check_params(proc->cmd_save.params))
		return (0);
	r1 = proc->cmd_save.params[0];
	r2 = proc->cmd_save.params[1];
	r3 = proc->cmd_save.params[2];
	proc->reg[r3] = proc->reg[r1] + proc->reg[r2];
	return (1);
}
