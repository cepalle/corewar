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

int		main(int argc, char **argv)
{
	t_vm		vm;
	t_input		input;

	ft_bzero(&vm, sizeof(t_vm));
	ft_bzero(&input, sizeof(t_input));
	if (input_cmdline(argc, argv, &input) == 0)
		return (1);
	vm_init(&vm, input);

//	vm_print(&vm);
	input_free(&input);
	vm_run(&vm);
	//vm_print(&vm);
	ft_printf("last live joueur 0 = %d\n", vm.player[0].last_live);
	ft_printf("last live joueur 1 = %d\n", vm.player[1].last_live);

	ft_printf("nb live joueur 0 = %d\n", vm.player[0].live);
	ft_printf("nb live joueur 1 = %d\n", vm.player[1].live);


	vm_free(&vm);
	return (0);
}
