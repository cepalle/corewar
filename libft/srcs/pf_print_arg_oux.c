/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_arg.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:06:54 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:15 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		pf_padding_precision_oux(t_format *fm, char *str_arg)
{
	int		len;
	int		precision;

	precision = fm->precision;
	len = pf_strlen(str_arg);
	return (pf_put_n_char('0', precision - len));
}

int		pf_print_flags_oux(t_format *fm, char *str_arg)
{
	int		len;

	(void)str_arg;
	len = 0;
	if (fm->flag_hash)
	{
		if (fm->type == 'o' && fm->precision < (int)pf_strlen(str_arg))
		{
			pf_putchar('0');
			len++;
		}
		else if (fm->type == 'x')
		{
			pf_putchar('0');
			pf_putchar('x');
			len += 2;
		}
		else if (fm->type == 'X')
		{
			pf_putchar('0');
			pf_putchar('X');
			len += 2;
		}
	}
	return (len);
}

int		pf_padding_width_oux(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	len = pf_strlen(str_arg);
	len = (len > fm->precision ? len : fm->precision);
	if (fm->flag_hash)
	{
		if (fm->type == 'o')
			len++;
		if (fm->type == 'x' || fm->type == 'X')
			len += 2;
	}
	if (str_arg[0] == '0' && fm->precision == 0)
		len--;
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}

int		put_oux(t_format *fm, char *str_arg)
{
	if (fm->type == 'o' && str_arg[0] == '0' && fm->flag_hash)
		return (0);
	if (!(str_arg[0] == '0' && fm->precision == 0))
		return (pf_putstr(str_arg));
	return (0);
}

int		pf_print_arg_oux(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
	{
		nb_print += pf_print_flags_oux(fm, str_arg);
		nb_print += pf_padding_precision_oux(fm, str_arg);
		nb_print += put_oux(fm, str_arg) + pf_padding_width_oux(fm, str_arg);
	}
	else if (fm->flag_0)
	{
		nb_print += pf_print_flags_oux(fm, str_arg);
		nb_print += pf_padding_width_oux(fm, str_arg);
		nb_print += pf_padding_precision_oux(fm, str_arg);
		nb_print += put_oux(fm, str_arg);
	}
	else
	{
		nb_print += pf_padding_width_oux(fm, str_arg);
		nb_print += pf_print_flags_oux(fm, str_arg);
		nb_print += pf_padding_precision_oux(fm, str_arg);
		nb_print += put_oux(fm, str_arg);
	}
	free(str_arg);
	return (nb_print);
}
