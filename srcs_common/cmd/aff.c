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
	unsigned char	c;
	int				er;

	(void)vm;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	c = (unsigned char)(read_param(vm->process + ipr, 0, &er) % 256);
	if (er)
		return (0);
	ft_printf("%c", c);
	return (1);
}
