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

void	ft_debug_init_vm(t_vm vm)
{
	int a;

	a = 0;
	ft_printf("d = %d et nb_d = %d\n", vm.d, vm.d_nb);
	ft_printf("dl = %d et nb_dl = %d\n", vm.dl, vm.dl_nb);
	ft_printf("nombre de joueurs de la vm est %d\n", vm.nb_p);
	if (vm.db == 1)
		ft_printf("debug mod active\n");
	while (a < vm.nb_p)
	{
		ft_printf("le numero du joueur %d est %d\n", a, vm.player[a].id);
		ft_printf("la taille du programme est de %d\n",
				vm.player[a].head.prog_size);
		ft_printf("le nom du programme est %d\n", vm.player[a].head.prog_name);
		ft_printf("comment :\n %s\n", vm.player[a].head.comment);
		ft_printf("magic = %x\n", vm.player[a].head.magic);
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
	ft_debug_init_vm(vm);
	input_free(&input);
//	vm_run(&vm);
//	vm_free(&vm);
	return (0);
}
