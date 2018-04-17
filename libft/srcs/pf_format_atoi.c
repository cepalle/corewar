/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   format_atoi.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:02:36 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:46 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		pf_format_atoi(const char *format, int *i)
{
	int	res;

	res = 0;
	while (pf_is_num(format[*i]))
	{
		res = res * 10 + format[*i] - '0';
		(*i)++;
	}
	return (res);
}
