/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:50:55 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:50:56 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	vm_print(t_vm *vm)
{
	int i;

	i = 0;
	while (i < vm->nb_p)
	{
		header_print(vm->player[i].head);
		i++;
	}
	vm_dump_mem(vm);
}
