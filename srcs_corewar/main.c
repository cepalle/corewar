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

/*void	ft_print_vm(t_vm vm)
{
	int a;
	int b;

	a = -1;
	ft_printf("ft_print_vm\n");
	while (++a < vm.nb_p)
	{
		ft_printf("%x\n", vm.player[a].head.magic);
		ft_printf("%s\n", vm.player[a].head.prog_name);
		ft_printf("%u\n", vm.player[a].head.prog_size);
		ft_printf("%s\n", vm.player[a].head.comment);
		b = -1;

		while ((unsigned int)++b < vm->player[a].head.prog_size)
			ft_printf("%0.2hhx ", vm->player[a].prog[b]);

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
*/


int		main(int argc, char **argv)
{
	int b = -1;
	t_vm		vm;
	t_input		input;

	ft_bzero(&vm, sizeof(t_vm));
	if (ft_check_error(argc, argv, &input) == 0)
		return (0);

	/*ft_printf("%x\n", input.head[0].magic);
	ft_printf("%s\n", input.head[0].prog_name);
	ft_printf("%u\n", input.head[0].prog_size);
	ft_printf("%s\n", input.head[0].comment);

	while ((unsigned int)++b < input.head[0].prog_size)
		ft_printf("%0.2hhx ",  input.prog[0][b]);

	b = -1;

	ft_printf("%x\n", input.head[1].magic);
	ft_printf("%s\n", input.head[1].prog_name);
	ft_printf("%u\n", input.head[1].prog_size);
	ft_printf("%s\n", input.head[1].comment);
	while ((unsigned int)++b < input.head[1].prog_size)
		ft_printf("%0.2hhx ",  input.prog[1][b]);
*/


//	input = input_cmd(argc, argv);

//	ft_create_map(&vm, input); // initialiser vm (t_iniput_cmd, &vm);
	// if error free(input)
//	ft_print_vm(&vm);
//	ft_run_vm(&vm, input_cmd);
	//free
	return (0);
}

//TODO NE PAS OUBLIER DE FREE