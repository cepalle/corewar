/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   header_print.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 12:08:42 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 12:08:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <op.h>
#include "libft.h"

void	header_print(t_header head)
{
	ft_printf("### HEADER Player\n");
	ft_printf("%x\n", head.magic);
	ft_printf("%s\n", head.prog_name);
	ft_printf("%u\n", head.prog_size);
	ft_printf("%s\n", head.comment);
}
