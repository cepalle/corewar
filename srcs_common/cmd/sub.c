/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   sub.c                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:51 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

static int	op_sub(int a, int b)
{
	return (a - b);
}

int			cmd_sub(t_vm *vm, int ipr)
{
	return (do_op(vm, ipr, &op_sub));
}
