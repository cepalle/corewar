/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 17:14:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 15:30:11 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "../libft/includes/libft.h"

void	ft_print_vm(t_vm *vm)
{
	int a;
	int b;

	a = 0;
	ft_printf("ft_print_vm\n");
	while (a < vm->nb_p)
	{
		//	nb magic code sur 4 octet pour lire en int il faut reverse
		swap_4(&vm->player[a].head.magic);
		ft_printf("%x\n", vm->player[a].head.magic);
		ft_printf("%s\n", vm->player[a].head.prog_name);

		//	nb code sur 4 octet a swap pour lire bon nombre
		swap_4(&vm->player[a].head.prog_size);
		ft_printf("%u\n", vm->player[a].head.prog_size);
		ft_printf("%s\n", vm->player[a].head.comment);
		b = 0;
		while (b < vm->player[a].head.prog_size)
		{
			ft_printf("%0.2hhx ", vm->player[a].prog[b]);
			b++;
		}
		ft_printf("\n\n\n\n");
		a++;
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


int 	main(int argc, char **argv)
{

	t_vm		*vm;

	vm = malloc(sizeof(vm));
	if (ft_check_error(argc, argv) == 0)
		return (0);
	ft_create_player(argv, vm);
	ft_create_map(vm);
	ft_print_vm(vm);

	return (0);
}
