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
	unsigned int addr;
	int reg;

	reg = vm->process[ipr].cmd_save.params[0];
	if (reg > 16 || reg < 0)
	{
//	passer proc->carry = 0; ?
		return (0);
	}
	addr = vm->process[ipr].PC + (vm->process[ipr].cmd_save.params[1]
								  + vm->process[ipr].cmd_save.params[2]);
	vm_write_4(vm, addr, (unsigned int)vm->process[ipr].reg[reg]);
	vm->process[ipr].carry = 1;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	return(1);
	}

