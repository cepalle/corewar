/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_read.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 12:52:13 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 12:52:14 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

signed	char	vm_read_1(t_vm *vm, unsigned int pc)
{
	return (vm->tab[cal_pc_add(pc, 0)]);
}

signed	short	vm_read_2(t_vm *vm, unsigned int pc)
{
	unsigned short	stock;
	int				i;

	i = 0;
	stock = 0;
	while (i < 2)
	{
		stock = stock << 8;
		stock = stock + vm->tab[cal_pc_add(pc, i)];
		i++;
	}
	return (stock);
}

signed	int		vm_read_4(t_vm *vm, unsigned int pc)
{
	unsigned	int	stock;
	int				i;

	i = 0;
	stock = 0;
	while (i < 4)
	{
		stock = stock << 8;
		stock = stock + vm->tab[cal_pc_add(pc, i)];
		i++;
	}
	return (stock);
}
