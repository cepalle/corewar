/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ld.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:53 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:54 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

// TODO carry
int		cmd_ld(t_vm *vm, int ipr)
{
	int		er;
	int		ri;
	int		p;

	er = 0;
	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	p = get_param(proc, 0, &er);
	ri = get_i_reg(proc, 1, &er);
	if (er)
		return (0);
	proc->reg[ri] = p;
	return (1);
}
