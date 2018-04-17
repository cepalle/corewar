/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_print_arg_s.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:35:56 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:20 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_padding_width_s(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	if (fm->lenght == 'l')
		len = pf_wstrlen((wchar_t *)str_arg);
	else
		len = pf_strlen(str_arg);
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}

int		pf_put_s(char *str, t_format *fm)
{
	int		len;
	wchar_t	*wstr;

	if (fm->lenght != 'l')
		return (pf_putstr(str));
	wstr = (wchar_t *)str;
	len = 0;
	while (*wstr)
	{
		len += pf_put_wc(*wstr);
		wstr++;
	}
	return (len);
}

int		pf_print_arg_s(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
	{
		nb_print += pf_put_s(str_arg, fm);
		nb_print += pf_padding_width_s(fm, str_arg);
	}
	else
	{
		nb_print += pf_padding_width_s(fm, str_arg);
		nb_print += pf_put_s(str_arg, fm);
	}
	free(str_arg);
	return (nb_print);
}
