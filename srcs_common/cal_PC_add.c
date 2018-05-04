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
	ft_printf("get_op_name\n");
	return ((pc + MEM_SIZE + (to_add % MEM_SIZE)) % MEM_SIZE);
}
