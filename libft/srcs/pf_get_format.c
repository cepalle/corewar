/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_format.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:57:24 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:47 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int			pf_get_format_width(const char *format, int *i)
{
	if (pf_is_num(format[*i]))
		return (pf_format_atoi(format, i));
	return (-1);
}

int			pf_get_format_precision(const char *format, int *i)
{
	if (format[*i] == '.')
	{
		(*i)++;
		return (pf_format_atoi(format, i));
	}
	return (-1);
}

int			pf_get_format_lenght(const char *format, int *i)
{
	char tmp;

	if (format[*i] == 'h' && format[*i + 1] == 'h')
	{
		(*i) += 2;
		return ('H');
	}
	else if (format[*i] == 'l' && format[*i + 1] == 'l')
	{
		(*i) += 2;
		return ('L');
	}
	else if (format[*i] == 'h' || format[*i] == 'l' ||
			format[*i] == 'j' || format[*i] == 'z')
	{
		tmp = format[*i];
		(*i)++;
		return (tmp);
	}
	return ('\0');
}

void		pf_feed_format(t_format *fm, int *i, const char *format)
{
	while (1)
	{
		if (is_flags(format[*i]))
			pf_get_format_flags(format, i, fm);
		else if (is_num(format[*i]))
			fm->width = pf_get_format_width(format, i);
		else if (format[*i] == '.')
			fm->precision = pf_get_format_precision(format, i);
		else if (is_lenght(format[*i]))
			fm->lenght = pf_get_format_lenght(format, i);
		else
		{
			fm->type = pf_get_format_type(format, i, fm);
			return ;
		}
	}
}

t_format	pf_get_format(const char *format, int *i)
{
	t_format	fm;

	fm.flag_hash = 0;
	fm.flag_0 = 0;
	fm.flag_minus = 0;
	fm.flag_plus = 0;
	fm.flag_space = 0;
	fm.width = -1;
	fm.precision = -1;
	fm.lenght = '\0';
	fm.type = '\0';
	pf_feed_format(&fm, i, format);
	return (fm);
}
