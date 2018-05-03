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
#include "libft.h"

int		cmd_st(t_vm *vm, t_proc *proc)
{
	unsigned int addr;
	int reg;

	reg = proc->cmd_save.params[0];
	if (reg > 16 || reg < 0)
	{
//		passer proc->carry = 0; ?
		return (0);
	}
	addr = proc->PC + (proc->cmd_save.params[1] % IDX_MOD);
	vm_write_4(vm, addr, (unsigned int)proc->reg[reg]);
	proc->carry = 1;
	return(1);
}

