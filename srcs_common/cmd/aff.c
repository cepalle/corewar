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

	init_vm_proc(&vm_proc, vm, ipr, 1);
	c = (unsigned char)(read_param(&vm_proc, 0) % 256);
	if (vm_proc.er)
		return (0);
	if (!vm->l && !vm->db)
		ft_printf("%c", c);
	return (1);
}
