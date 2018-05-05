/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   st.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:36 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h" // a supprimer

int		cmd_st(t_vm *vm, int ipr)
{
	t_vm_proc		vm_proc;
	int				p1;

	ft_printf("\ncmd_st %d\n", ipr);
	init_vm_proc(&vm_proc, vm, ipr, 1);
	p1 = read_param(&vm_proc, 0);
	load_param(&vm_proc, 1, p1);

	ft_printf("reg num %d\n", vm->process[ipr].cmd_save.params[0]);
	ft_printf("reg val %d\n", vm->process[ipr].reg[0]);
	ft_printf("data %d == %d\n", p1, vm->process[ipr].reg[0]);

	vm->process[ipr].PC = cal_pc_add(vm->process[ipr].PC,
		vm->process[ipr].cmd_save.cmd_len);
	if (vm_proc.er)
		return (0);
	vm->process[ipr].carry = 1;
	return (1);
}
