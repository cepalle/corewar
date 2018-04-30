/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 17:14:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 09:52:27 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "../libft/includes/libft.h"

void	ft_print_vm(t_vm *vm)
{
	int a;
	int b;

	a = -1;
	ft_printf("ft_print_vm\n");
	while (++a < vm->nb_p)
	{
		ft_printf("%x\n", vm->player[a].head.magic);
		ft_printf("%s\n", vm->player[a].head.prog_name);
		ft_printf("%u\n", vm->player[a].head.prog_size);
		ft_printf("%s\n", vm->player[a].head.comment);
		b = -1;
		while (++b < vm->player[a].head.prog_size)
			ft_printf("%0.2hhx ", vm->player[a].prog[b]);
		ft_printf("\n\n\n\n");
	}
	b = 1;
	a = -1;
	while (++a < MEM_SIZE)
	{
		ft_printf("%0.2hhx ", vm->tab[a]);
		if (b % 64 == 0)
			ft_printf("\n");
		b++;
	}
}

int		main(int argc, char **argv)
{
	t_vm		vm;

	ft_bzero(&vm, sizeof(t_vm));
	if (ft_check_error(argc, argv) == 0)
		return (0);
	ft_create_player(argv, &vm);
	ft_create_map(&vm);
	ft_print_vm(&vm);
	return (0);
}
