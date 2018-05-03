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
	return (vm->tab[PC % MEM_SIZE]);
}

unsigned short 	vm_read_2(t_vm *vm, unsigned int PC)
{
	unsigned short 	stock;
	int 			i;
	int 			left;

	i = 0;
	left = 0;
	stock = 0;
	while (i < 2)
	{
		stock = stock << left;
		stock = stock + vm->tab[(PC + i) % MEM_SIZE];
		left = left + 8;
		i++;
	}
	swap_2(&stock);
	return (stock);
}

unsigned int	vm_read_4(t_vm *vm, unsigned int PC)
{
	unsigned int 	stock;
	int 			i;
	int 			left;

	i = 0;
	left = 0;
	stock = 0;
	while (i < 4)
	{
		stock = stock << left;
		stock = stock + vm->tab[(PC + i) % MEM_SIZE];
		left = left + 8;
		i++;
	}
	swap_4(&stock);
	return (stock);
}
