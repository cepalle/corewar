/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_param.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 15:38:10 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 15:38:11 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <corewar.h>

int get_param(t_proc *proc, int i, int *er)
{
	if (proc->cmd_save.params_type[i] == REG_CODE)
	{
		if (proc->cmd_save.params[i] > 0 &&
			proc->cmd_save.params[i] < 17)
			return proc->reg[proc->cmd_save.params[i] - 1];
		*er = 1;
	}
	return proc->cmd_save.params[i];
}
