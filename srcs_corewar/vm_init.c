/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   vm_init.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 17:11:45 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 10:43:22 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "op.h"
#include "corewar.h"
#include <fcntl.h>

static	unsigned	int	ft_check_num_player_input(t_input input,
													 int nb)
{
	int b;

	b = -1;
	while (++b < MAX_PLAYERS)
	{
		if ((unsigned int)nb == (unsigned int)input.num_player[b])
			return (0);
	}
	return (1);
}

static	unsigned	int	ft_check_num_player_vm(t_vm *vm, unsigned int a,
													 int nb)
{
	unsigned int b;

	b = 0;
	while (b < a)
	{
		if ((unsigned int)nb == vm->player[b].id)
			return (0);
		b++;
	}
	return (1);
}

static				int	ft_generate_nb(t_vm *vm, t_input input, unsigned int a)
{
	int nb;

	nb = -1;
	while (1)
	{
		if (ft_check_num_player_input(input, nb) == 1
			&& ft_check_num_player_vm(vm, a, nb) == 1)
			return (nb);
		nb--;
	}
}

//static	void			process_swap(t_vm *vm, t_input input);

static	void			process_init(t_vm *vm, t_input input)
{
	int				a;
	unsigned int	res;
	int				placement;

	a = 0;
	res = 0;
	placement = MEM_SIZE / input.nb_p;
	while (a < vm->nb_p)
	{
		vm->process[vm->nb_p - 1 - a].PC = res;
		vm->process[vm->nb_p - 1 - a].carry = 0;
		ft_memcpy(vm->tab + res, input.prog[a], input.head[a].prog_size);
		res = res + placement;
		ft_bzero(&vm->process[vm->nb_p - 1 - a].cmd_save, sizeof(t_cmd_save));
		a++;
	}
}

static	void			player_init(t_vm *vm, t_input input)
{
	unsigned int a;

	a = 0;
	while (a < input.nb_p)
	{
		vm->player[a].head.prog_size = input.head[a].prog_size;
		vm->player[a].head.magic = input.head[a].magic;
		vm->player[a].id = 0;
		if (input.num_player[a] != 0)
			vm->player[a].id = (unsigned int)input.num_player[a];
		else
			vm->player[a].id = (unsigned int)ft_generate_nb(vm, input, a);
		vm->process[vm->nb_p - 1 - a].reg[0] = vm->player[a].id;
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

void					vm_init(t_vm *vm, t_input input)
{
	vm->d = input.d;
	vm->db = input.db;
	vm->nb_p = input.nb_p;
	vm->d_nb = input.d_nb;
	vm->process = ft_memalloc(sizeof(t_proc) * LEN_INIT_PROC);
	vm->nb_process = (unsigned int)vm->nb_p;
	vm->len_process = LEN_INIT_PROC;
	ft_memset(vm->tab, 0, MEM_SIZE);
	vm->cycle = 0;
	player_init(vm, input);
}
