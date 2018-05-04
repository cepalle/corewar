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

int		cmd_aff(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	unsigned char	c;

	ft_printf("cmd_aff\n");
	init_vm_proc(&vm_proc, vm, ipr, 0);
	c = (unsigned char)(read_param(&vm_proc, 0) % 256);
	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
									vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	ft_printf("%c", c);
	return (1);
}
