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

static int end = 0;

int		will_exec(t_vm *vm)
{
	int i;

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
	int i;

	i = 0;
	vm_dump_mem_color(vm);
	ft_printf("CYCLE: %d: \n", vm->cycle);
	ft_printf("CYCLE_TO_DIE: %d\n", vm->cycle_to_die);
	ft_printf("NEXT_DIE: %d\n", vm->cycle_to_die - (vm->cycle - vm->cycle_last_check));
	while (i < vm->nb_process)
	{
		ft_printf("proc %2d wait: %4d nb_live: %3d PC: %4d cmd: %5s\n", i, vm->process[i].cmd_save.cycle_wating,
				vm->process[i].nb_live, vm->process[i].PC, get_op_cmd(vm->process[i].cmd_save.opcode).name);
		i++;
	}
}

void	debug(t_vm *vm)
{
	char	*line;

	if (will_exec(vm) && !end)
	{
		vm_print(vm);
		if (get_next_line(0, &line) > 0)
		{
			if (ft_strequ(line, "end"))
				end = 1;
			free(line);
		}
	}
}
