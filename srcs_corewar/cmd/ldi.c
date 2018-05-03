/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ldi.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:59 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:00 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */



#include <corewar.h>

int		cmd_ldi(t_vm *vm, t_proc *proc)
{
	int		er;
	int		p1;
	int		p2;
	int		ri3;

	er = 0;
	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	p1 = get_param(proc, 0, &er);
	p2 = get_param(proc, 1, &er);
	ri3 = get_i_reg(proc, 2, &er);
	if (er)
		return (0);
	proc->reg[ri3] = vm_read_4(vm, proc->PC + p1 + p2); // IDX_MOD ?
	return (1);
}
