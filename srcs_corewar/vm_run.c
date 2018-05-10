/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_run.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:51:05 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:51:06 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	vm_run(t_vm *vm)
{
	int		nb_no_decr;
	int		a;

	a = 0;
	ft_printf("Introducing contestants...\n");
	while (a < vm->nb_p)
	{
		ft_printf("* Player %d, weighing %d bytes, '%s' ('%s') !\n", a + 1,
				vm->player[a].head.prog_size, vm->player[a].head.prog_name,
				vm->player[a].head.comment);
		a++;
	}
	vm->cycle = 0;
	vm->cycle_last_check = vm->cycle;
	vm->cycle_to_die = CYCLE_TO_DIE;
	nb_no_decr = 1;
	while (!vm->d || vm->d_nb > vm->cycle)
		if (!vm_cycle(vm, &nb_no_decr))
			break ;
	vm_display_res(vm);
}
