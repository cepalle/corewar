/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_cycle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:50:44 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:50:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>
#include "libft.h" // a supprimer une fois debug termine

void	vm_cycle(t_vm *vm)
{
	unsigned int	i;

//	ft_printf("vm_cycle\n");
	i = vm->nb_process;
	while (i)
	{
		proc_exec(vm, i - 1);
		i--;
	}
}
