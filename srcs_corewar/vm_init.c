/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_init.c                                        .::    .:/ .      .::   */
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

static	void	process_init(t_vm *vm, t_input input)
{
	int a;
	int res;
	int placement;

	a = 0;
	res = 0;
	placement = MEM_SIZE / input.nb_p;
	while (a < vm->nb_p)
	{
		vm->process[a].PC = res;
		vm->process[a].carry = 0;
		ft_memcpy(vm->tab + res, input.prog[a], input.head[a].prog_size);
		res = res + placement;
		ft_bzero(&vm->process[a].cmd_save, sizeof(t_cmd_save));
		a++;
	}
}

static	void	player_init(t_vm *vm, t_input input)
{
	int a;

	a = 0;
	while (a < input.nb_p)
	{
		vm->player[a].head.prog_size = input.head[a].prog_size;
		vm->player[a].head.magic = input.head[a].magic;
		vm->player[a].id = a;
		vm->process[a].reg[0] = vm->player[a].id;
		vm->player[a].last_live = 0;
		vm->player[a].live = 0;
		vm->player[a].is_alive = 1;
		ft_strncpy(vm->player[a].head.prog_name, input.head[a].prog_name,
			input.head->prog_size);
		ft_strncpy(vm->player[a].head.comment, input.head[a].comment,
				COMMENT_LENGTH + 1);
		a++;
	}
	process_init(vm, input);
}

void			vm_init(t_vm *vm, t_input input)
{
	vm->d = input.d;
	vm->nb_p = input.nb_p;
	vm->process = ft_memalloc(sizeof(t_proc) * LEN_INIT_PROC);
	vm->nb_process = (unsigned int)vm->nb_p;
	vm->len_process = LEN_INIT_PROC;
	ft_memset(vm->tab, 0, MEM_SIZE);
	vm->cycle = 0;
	player_init(vm, input);
}
