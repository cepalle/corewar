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

	ft_printf("nombre de joueurs cree = %d\n", input.nb_p);
	if (input.d == 1)
		ft_printf("-d option enable\n");
	ft_printf("nb_d = %d, d = %d\n", input.d_nb, input.d);
	if (input.db == 1)
		ft_printf("-debug option enable\n");
	if (input.nc == 1)
		ft_printf("-nCurse option enable\n");

	unsigned int a = 0;
	while (a < input.nb_p)
	{
		ft_printf("magic = %x\n", input.head[a].magic);
		ft_printf("prog_name = %s\n", input.head[a].prog_name);
		ft_printf("comment = %s\n", input.head[a].comment);
		ft_printf("prog_size = %x\n", input.head[a].prog_size);
		ft_printf("numero du joueur %d est de %d\n",a + 1,  input.num_player[a]);
		a++;
	}


	vm_init(&vm, input);
	ft_printf("\n\n\n\n\n\npour vm");
	a = 0;
	while (a < input.nb_p)
	{
		ft_printf("magic = %x\n", vm.player[a].head.magic);
		ft_printf("prog_name = %s\n",  vm.player[a].head.prog_name);
		ft_printf("comment = %s\n",  vm.player[a].head.comment);
		ft_printf("prog_size = %x\n",  vm.player[a].head.prog_size);
		ft_printf("numero du joueur %d est de %d\n",a + 1,  vm.player[a].id);
		a++;
	}

//	input_free(&input);
	vm_run(&vm);
//	vm_free(&vm);
	return (0);
}
