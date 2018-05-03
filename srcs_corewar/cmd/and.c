/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   and.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:42 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <corewar.h>

int		cmd_and(t_vm *vm, t_proc *proc)
{
	unsigned int	p1;
	unsigned int	p2;
	unsigned int	reg;

	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	p1 = get_param(proc, 0);
	p2 = get_param(proc, 1);
	proc->reg[reg] = p1 & p2;
	return (1);
}
