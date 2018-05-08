/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_dump_mem.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 14:29:23 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 14:29:25 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "corewar.h"

int		is_pc_proc(t_vm *vm, int pc)
{
	int i;

	i = 0;
	while (i < vm->nb_process)
	{
		if (vm->process[i].pc == (unsigned)pc)
			return (1);
		i++;
	}
	return (0);
}

void	vm_dump_mem_color(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE / DUMP_LEN)
	{
		j = 0;
		if (i)
			ft_printf("%#.4x : ", i * DUMP_LEN);
		else
			ft_printf("0x0000 : ");
		while (j < DUMP_LEN)
		{
			if (is_pc_proc(vm, i * DUMP_LEN + j))
				ft_printf("\033[34m%.2hhx\033[0m ", vm->tab[i * DUMP_LEN + j]);
			else if (vm->tab[i * DUMP_LEN + j])
				ft_printf("\033[31m%.2hhx\033[0m ", vm->tab[i * DUMP_LEN + j]);
			else
				ft_printf("%.2hhx ", vm->tab[i * DUMP_LEN + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}

void	vm_dump_mem(t_vm *vm)
{
	int i;
	int j;

	i = 0;
	while (i < MEM_SIZE / DUMP_LEN)
	{
		j = 0;
		if (i)
			ft_printf("%#.4x : ", i * DUMP_LEN);
		else
			ft_printf("0x0000 : ");
		while (j < DUMP_LEN)
		{
			ft_printf("%.2hhx ", vm->tab[i * DUMP_LEN + j]);
			j++;
		}
		ft_printf("\n");
		i++;
	}
}
