/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_print.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:50:55 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:50:56 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

int		will_exec(t_vm *vm)
{
	unsigned int i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (!vm->process[i].cmd_save.cycle_wating)
			return (1);
		i++;
	}
	return (0);
}

void	vm_print(t_vm *vm)
{
	unsigned int i;

	i = 0;
	vm_dump_mem_color(vm);
	ft_printf("CYCLE: %d: \n", vm->cycle);
	while (i < vm->nb_process)
	{
		ft_printf("proc %d wait: %d\n", i, vm->process[i].cmd_save.cycle_wating);
		i++;
	}
}

void	debug(t_vm *vm)
{
	char	*line;

	if (will_exec(vm))
	{
		vm_print(vm);
		if (get_next_line(0, &line) > 0)
			free(line);
	}
}
