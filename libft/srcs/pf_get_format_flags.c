/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_get_format_flags.c                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 15:46:56 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:48 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		pf_get_format_flags(const char *format, int *i, t_format *fm)
{
	while (is_flags(format[*i]))
	{
		if (format[*i] == '#')
			fm->flag_hash = 1;
		else if (format[*i] == '0')
			fm->flag_0 = 1;
		else if (format[*i] == '-')
			fm->flag_minus = 1;
		else if (format[*i] == '+')
			fm->flag_plus = 1;
		else
			fm->flag_space = 1;
		(*i)++;
	}
}
