/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_flags.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:07:09 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:22 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	put_hash(t_format *fm, char *str_arg)
{
	int		len;

	len = 0;
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
	return (len);
}

int			pf_print_flags(t_format *fm, char *str_arg)
{
	int		len;

	len = 0;
	if (str_arg[0] == '-')
	{
		pf_putchar('-');
		len++;
	}
	else if (fm->flag_space)
	{
		pf_putchar(' ');
		len++;
	}
	else if (fm->flag_plus)
	{
		pf_putchar('+');
		len++;
	}
	else if (fm->flag_hash)
		len += put_hash(fm, str_arg);
	return (len);
}
