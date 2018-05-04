/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sti.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:42 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

//Prend un registre, et deux index (potentiellement des registres).
//Additionne les deux derniers, utilise cette somme comme une adresse ou sera copiée la valeur du premier paramètre.

int		cmd_sti(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				ri1;
	int				ri2;
	int				res;

	init_vm_proc(&vm_proc, vm, ipr, 0);

	ri1 = read_param(&vm_proc, 1);
	ri2 = read_param(&vm_proc, 2);
	res = ri1 + ri2;
	set_param(&vm_proc, 0, res);
	set_param(&vm_proc, 1, )
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = 1;
	return (1);
}

