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

void	vm_run(t_vm *vm)
{
	int		nb_no_decr;

	vm->cycle = 0;
	vm->cycle_last_check = vm->cycle;
	vm->cycle_to_die = CYCLE_TO_DIE;
	nb_no_decr = 1;
	while (!vm->d || vm->d_nb > vm->cycle)
		if (!vm_cycle(vm, &nb_no_decr))
			break ;
	vm_display_res(vm);
}
