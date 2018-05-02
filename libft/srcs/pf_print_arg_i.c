/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_print_arg_i.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 17:37:33 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:12 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_padding_precision_i(t_format *fm, char *str_arg)
{
	int		len;
	int		precision;

	precision = fm->precision;
	len = pf_strlen(str_arg);
	if (str_arg[0] == '-')
		len--;
	return (pf_put_n_char('0', precision - len));
}

int		pf_print_flags_i(t_format *fm, char *str_arg)
{
	int		len;

	len = 0;
	if (str_arg[0] == '-')
	{
		pf_putchar('-');
		len++;
	}
	else if (fm->flag_plus)
	{
		pf_putchar('+');
		len++;
	}
	else if (fm->flag_space)
	{
		pf_putchar(' ');
		len++;
	}
	return (len);
}

int		pf_padding_width_i(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	len = pf_strlen(str_arg);
	if (str_arg[0] == '-')
		len--;
	len = (len > fm->precision ? len : fm->precision);
	if (fm->flag_plus)
		len++;
	else if (fm->flag_space)
		len++;
	else if (str_arg[0] == '-')
		len++;
	if (str_arg[0] == '0' && fm->precision == 0)
		len--;
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}

int		pf_put_sn(t_format *fm, char *str_arg)
{
	int		nb_print;

	(void)fm;
	nb_print = 0;
	if (fm->precision == 0 && str_arg[0] == '0')
		return (0);
	if (str_arg[0] == '-')
		nb_print += pf_putstr(str_arg + 1);
	else
		nb_print += pf_putstr(str_arg);
	return (nb_print);
}

int		pf_print_arg_i(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
	{
		nb_print += pf_print_flags_i(fm, str_arg);
		nb_print += pf_padding_precision_i(fm, str_arg);
		nb_print += pf_put_sn(fm, str_arg) + pf_padding_width_i(fm, str_arg);
	}
	else if (fm->flag_0)
	{
		nb_print += pf_print_flags_i(fm, str_arg);
		nb_print += pf_padding_width_i(fm, str_arg);
		nb_print += pf_padding_precision_i(fm, str_arg);
		nb_print += pf_put_sn(fm, str_arg);
	}
	else
	{
		nb_print += pf_padding_width_i(fm, str_arg);
		nb_print += pf_print_flags_i(fm, str_arg);
		nb_print += pf_padding_precision_i(fm, str_arg);
		nb_print += pf_put_sn(fm, str_arg);
	}
	free(str_arg);
	return (nb_print);
}
