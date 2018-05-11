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

void	ft_debug_init_cmdline(t_input input)
{
	unsigned int a;

	a = 0;
	ft_printf("cmd d = %d et d_nb = %d\n", input.d, input.d_nb);
	ft_printf("cmd l = %d et dl_nb = %d\n", input.dl, input.dl_nb);
	ft_printf("cmd nombre de joueurs de la vm est %d\n", input.nb_p);
	if (input.db == 1)
		ft_printf("cmd debug mod active\n");
	while (a < input.nb_p)
	{
		ft_printf("cmd la taille du programme est de %d\n",
				input.head[a].prog_size);
		ft_printf("cmd le nom du programme est %s\n", input.head[a].prog_name);
		ft_printf("cmd comment :\n %s\n", input.head[a].comment);
		ft_printf("cmd magic = %x\n", input.head[a].magic);
		a++;
	}
}

void	ft_debug_init_vm(t_vm vm)
{
	int a;

	a = 0;
	ft_printf("vm d = %d et d_nb = %d\n", vm.d, vm.d_nb);
	ft_printf("vm l = %d\n", vm.l);
	ft_printf("vm nombre de joueurs de la vm est %d\n", vm.nb_p);
	if (vm.db == 1)
		ft_printf("vm debug mod active\n");
	while (a < vm.nb_p)
	{
		ft_printf("vm le numero du joueur %d est %d\n", a, vm.player[a].id);
		ft_printf("vm la taille du programme est de %d\n",
				vm.player[a].head.prog_size);
		ft_printf("vm le nom du programme est %s\n",
				vm.player[a].head.prog_name);
		ft_printf("vm comment :\n %s\n", vm.player[a].head.comment);
		ft_printf("vm magic = %x\n", vm.player[a].head.magic);
		a++;
	}
}

int		main(int argc, char **argv)
{
	t_vm		vm;
	t_input		input;

	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(&input, sizeof(t_input));
	if (input_cmdline(argc, argv, &input) == 0)
	{
		input_free(&input);
		return (1);
	}
	vm_init(&vm, input);
	input_free(&input);
	vm_run(&vm);
	vm_free(&vm);
	return (0);
}
