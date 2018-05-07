/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_cycle.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:50:44 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:50:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int		vm_cycle(t_vm *vm, unsigned int *cycle_last_check,
	unsigned int *cycle_to_check, unsigned int *nb_no_decr)
{
	if (vm->db)
		debug(vm);
	procs_exec(vm);
	vm->cycle++;
	if (vm->cycle - *cycle_last_check >= *cycle_to_check)
	{
		*cycle_last_check = vm->cycle;
		kill_proc(vm);
		if (!vm->nb_process)
			return (0);
		if (check_nb_live_proc(vm) || *nb_no_decr >= MAX_CHECKS)
		{
			*cycle_to_check -= CYCLE_DELTA;
			*nb_no_decr = 0;
		}
		reset_live(vm);
	}
	return (1);
}
