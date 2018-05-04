/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:51 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <corewar.h>

// TODO carry
int		cmd_sub(t_vm *vm, int ipr)
{
	int		er;
	int		ri1;
	int		ri2;
	int		ri3;

	er = 0;
	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	ri1 = get_i_reg(proc, 0, &er);
	ri2 = get_i_reg(proc, 1, &er);
	ri3 = get_i_reg(proc, 2, &er);
	if (er)
		return (0);
	proc->reg[ri3] = proc->reg[ri1] - proc->reg[ri2]; // order ?
	return (1);
}
