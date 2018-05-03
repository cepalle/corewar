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
	int a;
	int b;

	a = -1;
	while (++a < vm->nb_p)
	{
		ft_printf("%x\n", vm->player[a].head.magic);
		ft_printf("%s\n", vm->player[a].head.prog_name);
		ft_printf("%u\n", vm->player[a].head.prog_size);
		ft_printf("%s\n", vm->player[a].head.comment);

		ft_printf("\n\n\n\n");
	}
	b = 1;
	a = -1;
	//TODO: warning utilisation printf
	while (++a < MEM_SIZE)
	{
		if (vm->tab[a] == 0)
			printf("%0.2hhx ", vm->tab[a]);
		else
			printf("\x1b[38;2;255;00;00m%0.2hhx \x1b[0m", vm->tab[a]);
		if (b % 64 == 0)
			printf("\n");
		b++;
	}
}
