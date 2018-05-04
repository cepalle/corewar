/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_write.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:35:05 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:35:06 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"

void	vm_write_1(t_vm *vm, unsigned int pc, unsigned char data)
{
	vm->tab[cal_pc_add(pc, 0)] = data;
}

void	vm_write_2(t_vm *vm, unsigned int pc, unsigned short data)
{
	int				a;
	unsigned char	*ptr;

	a = 0;
	ptr = (unsigned char*)&data;
	swap_2(&data);
	while (a < 2)
	{
		vm->tab[cal_pc_add(pc, a)] = ptr[a];
		a++;
	}
}

void	vm_write_4(t_vm *vm, unsigned int pc, unsigned int data)
{
	int				a;
	unsigned char	*ptr;

	a = 0;
	ptr = (unsigned char*)&data;
	swap_4(&data);
	while (a < 4)
	{
		vm->tab[cal_pc_add(pc, a)] = ptr[a];
		a++;
	}
}
