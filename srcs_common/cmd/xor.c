/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   xor.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:56 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:58 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

// TODO carry
int		cmd_xor(t_vm *vm, t_proc *proc)
{
	int 			er;
	int				p1;
	int				p2;
	int				ri;

	(void)vm;
	er = 0;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	p1 = get_param(proc, 0, &er);
	p2 = get_param(proc, 1, &er);
	ri = get_i_reg(proc, 2, &er);
	if (er)
		return (0);
	proc->reg[ri] = p1 ^ p2;
	return (1);
}
