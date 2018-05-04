/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   proc_exec.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 09:00:04 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 09:00:05 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

void	proc_exec(t_vm *vm, t_proc *proc)
{
	t_cmd cmd;

	ft_printf("proc_exec\n");
	if (!proc->cmd_save.cmd &&
		!stock_cmd(vm, proc))
	{
		proc->PC++;
		proc->PC %= MEM_SIZE;
		return ;
	}
	proc->cmd_save.cycle_wating--;
	if (proc->cmd_save.cycle_wating <= 0)
	{
		cmd = (t_cmd)proc->cmd_save.cmd;
		ft_printf("je suis ici\n");
		cmd(vm, proc); // erreur avec envoi d'une adresse au lieu d'un int
		vm_dump_mem(vm);
		ft_bzero(&(proc->cmd_save), sizeof(t_cmd_save));
	}
}
