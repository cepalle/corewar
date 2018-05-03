/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   live.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:43:09 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:43:10 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#include <corewar.h>

void	live(t_vm *vm, t_proc *proc)
{
//	penser a ajouter le numero du process?
//	process mis en place pour gerer une liste de fonction
	vm->player[num_player].live = vm->player[num_player].live + 1;
	vm->player[num_player].last_live = vm->player[num_player].last_live + 1;
}
