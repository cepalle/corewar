/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   aff.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:42:36 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:42:37 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h"

int		cmd_aff(t_vm *vm, t_proc *proc)
{
	(void)vm;
	(void)proc;
	return 1;
	/*
	unsigned char c;

	(void)vm;
	proc->PC += proc->cmd_save.cmd_len;
	proc->PC %= MEM_SIZE;
	c = (unsigned char)(proc->cmd_save.params[0] % 256);
	ft_printf("%c", c);
	return (1);
	*/
}
