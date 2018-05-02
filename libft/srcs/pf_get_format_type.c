/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_get_format_type.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 09:53:50 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:49 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		pf_get_format_type(const char *format, int *i, t_format *fm)
{
	char tmp;

	if (format[*i] == 'S' || format[*i] == 'D' ||
			format[*i] == 'O' || format[*i] == 'U' ||
			format[*i] == 'C')
	{
		fm->lenght = 'l';
		tmp = format[*i] - 'A' + 'a';
		(*i)++;
		return (tmp);
	}
	if (format[*i])
	{
		tmp = format[*i];
		(*i)++;
		if (tmp == 'i')
			return ('d');
		return (tmp);
	}
	return ('\0');
}
