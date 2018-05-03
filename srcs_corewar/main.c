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
#include "libft.h"

void	ft_print_vm(t_vm vm)
{
	int a;
	int b;

	a = -1;
	while (++a < vm.nb_p)
	{
		ft_printf("%x\n", vm.player[a].head.magic);
		ft_printf("%s\n", vm.player[a].head.prog_name);
		ft_printf("%u\n", vm.player[a].head.prog_size);
		ft_printf("%s\n", vm.player[a].head.comment);

		ft_printf("\n\n\n\n");
	}
	b = 1;
	a = -1;
	//TODO: warning utilisation printf
	while (++a < MEM_SIZE)
	{
		if (vm.tab[a] == 0)
			printf("%0.2hhx ", vm.tab[a]);
		else
			printf("\x1b[38;2;255;00;00m%0.2hhx \x1b[0m", vm.tab[a]);
		if (b % 64 == 0)
			printf("\n");
		b++;
	}
}

int		main(int argc, char **argv)
{
	t_vm		vm;
	t_input		input;

	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(&input, sizeof(t_input));

	if (input_cmd(argc, argv, &input) == 0)
		return (1);
	vm_init(&vm, input);
	// free imput
	ft_print_vm(vm);
	//vm_run(&vm);
	vm.process = malloc(sizeof(t_proc)); // test ppichier temporaire
	ft_stock_cmd(&vm, vm.process);
	// free vm
	return (0);
}

//TODO NE PAS OUBLIER DE FREE
