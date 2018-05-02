/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_up_vm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 17:11:45 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 17:11:46 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "op.h"
#include "corewar.h"
#include <fcntl.h>


void			vm_init(t_vm *vm, t_input input)
{
	int a;
	int res;
	int placement;

	a = 0;
	res = 0;
	placement = MEM_SIZE / input.nb_p;

	vm->d = input.d;
	vm->nb_p = input.nb_p;

	ft_memset(vm->tab, 0, MEM_SIZE);

	while (a < input.nb_p)
	{
		vm->player[a].head.prog_size = input.head[a].prog_size;
		vm->player[a].head.magic  = input.head[a].magic;
		ft_strncpy(vm->player[a].head.prog_name, input.head[a].prog_name, input.head->prog_size);
		ft_strncpy(vm->player[a].head.comment, input.head[a].comment, COMMENT_LENGTH + 1);
		ft_memcpy(vm->tab + res, input.prog[a], input.head[a].prog_size);
		res = res + placement;
		a++;
	}
}
