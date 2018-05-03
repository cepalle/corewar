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
	(void)vm;
	(void)proc;
	return 1;
	/*
	int addr;
	int *tab;

//	tab[0] = numero du registre
//	tab[1] = valeur du parametre
//	recuperer opcode pour savoir a quoi j'ai affaire

	addr = proc->PC + (proc->cmd_save.params[1] % IDX_MOD);

	vm_write_4(vm + addr, proc->cmd_save, REG_CONTENT_SIZE);

//	est ce qu'il faut faire un swap[2] ou swap[4]?

// 	changement de carry? passage de 1 a 0 ou  1 a 1

	vm->player[num_player].process[num_process].carry = 1;*/
}

