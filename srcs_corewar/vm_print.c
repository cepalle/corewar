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
	int i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (vm->process[i].cmd_save.cycle_wating == 0)
			return (1);
		i++;
	}
	return (0);
}

void	vm_print(t_vm *vm)
{
	int i;
	int len_line;

	i = 0;
	len_line = 32 + 32 * vm->l;
	vm_dump_mem_color(vm);
	ft_printf("CYCLE: %d: \n", vm->cycle);
	ft_printf("CYCLE_TO_DIE: %d\n", vm->cycle_to_die);
	ft_printf("NEXT_DIE: %d\n",
			vm->cycle_to_die - (vm->cycle - vm->cycle_last_check));
	ft_printf("NB_LIVE_TOT: %d\n", count_nb_live_proc(vm));
	ft_printf("NB_PROC_TOT: %d\n", vm->nb_process);
	while (i < vm->nb_process)
	{
		ft_printf(
	"proc_id %4d wait: %4d nb_live: %3d PC: %4d"
	" cmd: %7s line: %2d col : %2d carry: %d\n",
			vm->process[i].id, vm->process[i].cmd_save.cycle_wating,
			vm->process[i].nb_live, vm->process[i].pc,
			get_op_cmd(vm->process[i].cmd_save.opcode).name,
			vm->process[i].pc / len_line,
			vm->process[i].pc % len_line,
			vm->process[i].carry);
		i++;
	}
}

void	debug(t_vm *vm)
{
	char		*line;
	static int	end = 0;

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
