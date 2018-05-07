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
	unsigned int	cycle_last_check;
	unsigned int	cycle_to_check;
	unsigned int	nb_no_decr;

	vm->cycle = 0;
	cycle_last_check = vm->cycle;
	cycle_to_check = CYCLE_TO_DIE;
	nb_no_decr = 0;
	while (!vm->d || vm->d_nb > (int)vm->cycle)
		if (!vm_cycle(vm, &cycle_last_check, &cycle_to_check, &nb_no_decr))
			return ;
	vm_display_res(vm);
}
