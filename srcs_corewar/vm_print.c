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
	int j;

	i = 0;
	while (i < vm->nb_p)
	{
		header_print(vm->player[i].head);
		i++;
	}
	i = 0;
	while (i < MEM_SIZE / 32)
	{
		j = 0;
		if (i)
			ft_printf("%#.4x: ", i * 32); // prtinf ?
		else
			ft_printf("0x0000: ");
		while (j < 32)
		{
			ft_printf("%.2hhx ", vm->tab[i * 32 + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
