/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lfork.c                                          .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:04 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:05 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		cmd_lfork(t_vm *vm, int ipr)
{
	int 			er;
	int				p1;

	(void)vm;
	er = 0;
	vm->process[ipr].PC += vm->process[ipr].cmd_save.cmd_len;
	vm->process[ipr].PC %= MEM_SIZE;
	p1 = get_param(vm->process + ipr, 0, &er);
	if (er)
		return (0);
	vm_fork(vm, ipr, p1);
	return (1);
}
