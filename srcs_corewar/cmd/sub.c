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

int		sub(t_vm *vm, t_proc *proc)
{
//	penser a modifier carry si erreur ou pas
//	erreur potentiel : depassement int max
	return (player.process->reg[num_reg1] - player.process->reg[num_reg2]);
}
