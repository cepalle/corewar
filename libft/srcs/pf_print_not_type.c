/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_print_not_type.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 11:24:00 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:30 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	pf_padding_width_not_type(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	len = pf_strlen(str_arg);
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}

int	pf_print_not_type(t_format *fm, char *str_arg)
{
	int		nb_print;

	nb_print = 0;
	if (fm->flag_minus)
	{
		nb_print += pf_putstr(str_arg);
		nb_print += pf_padding_width_not_type(fm, str_arg);
	}
	else
	{
		nb_print += pf_padding_width_not_type(fm, str_arg);
		nb_print += pf_putstr(str_arg);
	}
	free(str_arg);
	return (nb_print);
}
