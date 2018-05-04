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

unsigned char 	vm_read_1(t_vm *vm, unsigned int PC)
{
	return (vm->tab[cal_PC_add(PC, 0)]);
}

unsigned short 	vm_read_2(t_vm *vm, unsigned int PC)
{
	unsigned short 	stock;
	int 			i;

	i = 0;
	stock = 0;
	while (i < 2)
	{
		stock = stock << 8;
		stock = stock + vm->tab[cal_PC_add(PC, i)];
		i++;
	}
	swap_2(&stock);
	return (stock);
}

unsigned int	vm_read_4(t_vm *vm, unsigned int PC)
{
	unsigned int 	stock;
	int 			i;

	i = 0;
	stock = 0;
	while (i < 4)
	{
		stock = stock << 8;
		stock = stock + vm->tab[cal_PC_add(PC, i)];
		i++;
	}
	swap_4(&stock);
	return (stock);
}
