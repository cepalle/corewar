/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   lldi.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:21 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:21 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <corewar.h>

//lldi : Opcode 0x0e. Pareil que ldi,
//mais n’applique aucun modulo aux adresses. Modifiera, par contre, le carry.

int		cmd_lldi(t_vm *vm, int ipr)
{
	int		er;
	int		p1;
	int		p2;
	int		ri3;

	er = 0;
	(void)vm;
	vm->process[ipr].PC = cal_PC_add(vm->process[ipr].PC,
									 vm->process[ipr].cmd_save.cmd_len);
	p1 = read_param(vm->process + ipr, 0, &er);
	p2 = read_param(vm->process + ipr, 1, &er);
	ri3 = set_param(vm->process + ipr, 2, &er);
	if (er)
		return (0);
	// READ a l'exec ?
	vm->process[ipr].reg[ri3] = vm_read_4(vm, vm->process[ipr].PC + (p1 + p2));
	vm->process[ipr].carry = 1;
	return (1);
}
