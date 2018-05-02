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




void			ft_create_map(t_vm *vm, t_input input)
{
	int a;
	int res;
	int placement;

	a = 0;
	res = 0;
	placement = MEM_SIZE / vm->nb_p;
	ft_printf("placement = %d\n", placement);
	ft_memset(vm->tab, 0, MEM_SIZE);
	while (a < vm->nb_p)
	{
		ft_memcpy(vm->tab + res, vm->player[a].prog,
				vm->player[a].head.prog_size);
		vm->player[a].PC = malloc(sizeof(t_proc));
		vm->player[a].PC->PC = res;
		res = res + placement;
		a++;
	}
}
