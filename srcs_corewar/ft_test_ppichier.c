/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ppichier_cmd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: ppichier <marvin@le-101.fr>                +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 11:34:40 by ppichier     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 11:34:41 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include "../includes/corewar.h"
#include "../includes/op.h"
#include "../libft/includes/libft.h"

void	ft_test_ppichier(t_vm *vm)
{
	int a = 2;

	vm->player[0].process = ft_memalloc(sizeof(t_proc));
	vm->player[0].process->reg[0] = ft_and(&vm->player[0],12, 4);
	ft_printf("le res = %d ", vm->player[0].process->reg[a]);
	ft_st(&vm->player[0], 200, 0, vm);
	vm_print(vm);
	ft_vm_run(vm, 0);

}

//TODO MALLOC DE STRUCT PC POUR TEST