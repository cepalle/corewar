/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   padding_precision.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:06:32 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:06 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	pf_padding_precision(t_format *fm, char *str_arg)
{
	int		len;
	int		precision;

	precision = fm->precision;
	len = pf_strlen(str_arg);
	if (fm->type == 'i' || fm->type == 'd' || fm->type == 'u' ||
			fm->type == 'o' || fm->type == 'x' || fm->type == 'X')
	{
		if (str_arg[0] == '-')
			len--;
		return (pf_put_n_char('0', precision - len));
	}
	return (0);
}
