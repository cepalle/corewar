/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_print_arg_c.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:33:55 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:11 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_padding_width_c(t_format *fm, char *str_arg)
{
	(void)str_arg;
	if (fm->width <= 0)
		return (0);
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - 1));
	return (pf_put_n_char(' ', fm->width - 1));
}

int		pf_put_c(char *c, t_format *fm)
{
	if (fm->lenght == 'l')
		return (pf_put_wc(*(wchar_t *)c));
	pf_putchar(c[0]);
	return (1);
}

int		pf_print_arg_c(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
	{
		nb_print += pf_put_c(str_arg, fm);
		nb_print += pf_padding_width_c(fm, str_arg);
	}
	else
	{
		nb_print += pf_padding_width_c(fm, str_arg);
		nb_print += pf_put_c(str_arg, fm);
	}
	free(str_arg);
	return (nb_print);
}
