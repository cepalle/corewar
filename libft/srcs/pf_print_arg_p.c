/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_print_arg_p.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 19:53:47 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:16 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int			pf_padding_precision_p(t_format *fm, char *str_arg)
{
	int		len;
	int		precision;

	precision = fm->precision;
	len = pf_strlen(str_arg);
	return (pf_put_n_char('0', precision - len));
}

int			pf_print_flags_p(t_format *fm, char *str_arg)
{
	int		len;

	(void)fm;
	(void)str_arg;
	len = 0;
	pf_putchar('0');
	pf_putchar('x');
	len += 2;
	return (len);
}

int			pf_padding_width_p(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	len = pf_strlen(str_arg);
	len = (len > fm->precision ? len : fm->precision);
	len += 2;
	if (str_arg[0] == '0' && fm->precision == 0)
		len--;
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}

static int	put_minus(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	nb_print += pf_print_flags_p(fm, str_arg);
	nb_print += pf_padding_precision_p(fm, str_arg);
	if (fm->precision != 0 || str_arg[0] != '0')
		nb_print += pf_putstr(str_arg);
	nb_print += pf_padding_width_p(fm, str_arg);
	return (nb_print);
}

int			pf_print_arg_p(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
		nb_print += put_minus(fm, str_arg);
	else if (fm->flag_0)
	{
		nb_print += pf_print_flags_p(fm, str_arg);
		nb_print += pf_padding_width_p(fm, str_arg);
		nb_print += pf_padding_precision_p(fm, str_arg);
		if (fm->precision != 0 || str_arg[0] != '0')
			nb_print += pf_putstr(str_arg);
	}
	else
	{
		nb_print += pf_padding_width_p(fm, str_arg);
		nb_print += pf_print_flags_p(fm, str_arg);
		nb_print += pf_padding_precision_p(fm, str_arg);
		if (fm->precision != 0 || str_arg[0] != '0')
			nb_print += pf_putstr(str_arg);
	}
	free(str_arg);
	return (nb_print);
}
