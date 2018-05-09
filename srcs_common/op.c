/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.c                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 09:52:27 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"
#include "corewar.h"

static t_op	g_op_tab[17] =
{
	{"live", 1, {T_DIR},
		1, 10, "alive", 0, 0, &cmd_live, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG},
		2, 5, "load", 1, 0, &cmd_ld, 6, 1},
	{"st", 2, {T_REG, T_IND | T_REG},
		3, 5, "store", 1, 0, &cmd_st, 6, 0},
	{"add", 3, {T_REG, T_REG, T_REG},
		4, 10, "addition", 1, 0, &cmd_add, 8, 1},
	{"sub", 3, {T_REG, T_REG, T_REG},
		5, 10, "soustraction", 1, 0, &cmd_sub, 8, 1},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, &cmd_and, 8, 1},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, &cmd_or, 8, 1},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, &cmd_xor, 8, 1},
	{"zjmp", 1, {T_DIR},
		9, 20, "jump if zero", 0, 1, &cmd_zjmp, 0, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1, &cmd_ldi, 8, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1, &cmd_sti, 8, 0},
	{"fork", 1, {T_DIR},
		12, 800, "fork", 0, 1, &cmd_fork, 0, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG},
		13, 10, "long load", 1, 0, &cmd_lld, 6, 1},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1, &cmd_lldi, 8, 1},
	{"lfork", 1, {T_DIR},
		15, 1000, "long fork", 0, 1, &cmd_lfork, 0, 0},
	{"aff", 1, {T_REG},
		16, 2, "aff", 1, 0, &cmd_aff, 4, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, 0, 0}
};

t_op		*gopt(void)
{
	return (g_op_tab);
}

t_op		get_op_name(char *cmd)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, cmd))
			return (gopt()[i]);
		i++;
	}
	return (gopt()[OP_TAB_LENGTH]);
}

t_op		get_op_cmd(int opcode)
{
	if (opcode > 16 || opcode < 1)
	{
		return (gopt()[OP_TAB_LENGTH]);
	}
	return (gopt()[opcode - 1]);
}
