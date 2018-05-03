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
#include <corewar.h>

/* ************************************************************************** */


unsigned char 	vm_read_1(t_vm *vm, unsigned int PC)
{
	return (vm->tab[PC % MEM_SIZE]);
}

unsigned short 	vm_read_2(t_vm *vm, unsigned int PC)
{
	//ne pas oublier le swap et copier

	swap_2(vm->tab[PC]);
	return (vm->tab[PC]);

}

unsigned int	vm_read_4(t_vm *vm, unsigned int PC)
{
	//ne pas oublier le swap et copier
	swap_4(vm->tab[PC]);
	return (vm->tab[PC]);
}