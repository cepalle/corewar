/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   cal_pc_add.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 09:18:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 09:18:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "op.h"
#include "libft.h" // a supprimer une fois debug termine

unsigned int	cal_pc_add(unsigned int pc, int to_add)
{
	ft_printf("cal_pc_add\n");
	ft_printf("PC: %u to_add: %d res: %u\n", pc, to_add, (pc + MEM_SIZE + (to_add % MEM_SIZE)) % MEM_SIZE);
	return ((pc + MEM_SIZE + (to_add % MEM_SIZE)) % MEM_SIZE);
}
