/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_usage.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 08:53:28 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 08:53:30 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void			ft_usage(void)
{
	ft_printf("ft_usage\n");
	ft_printf(
	"Usage: ./corewar [-d N -n N -dl N] "
	"<champion1.cor> <...>\n"
	"######################################################################\n"
	"    -d  N     : Dumps memory after N cycles then exits 32 display mode\n"
	"    -dl N     : Dumps memory after N cycles then exits 64 display mode\n"
	"    -n  N     : Choose champion number id N\n"
	"######################################################################\n");
}
