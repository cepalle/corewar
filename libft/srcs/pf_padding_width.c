/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   padding_width.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:56:51 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:08 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	pf_padding_width(t_format *fm, char *str_arg)
{
	int		len;

	if (fm->width <= 0)
		return (0);
	len = pf_strlen(str_arg);
	if (str_arg[0] == '-')
		len--;
	len = (len > fm->precision ? len : fm->precision);
	if (fm->flag_space || fm->flag_plus || str_arg[0] == '-')
		len++;
	if (fm->flag_hash)
	{
		if (fm->type == 'o')
			len++;
		if (fm->type == 'x' || fm->type == 'X')
			len += 2;
	}
	if (fm->flag_0)
		return (pf_put_n_char('0', fm->width - len));
	return (pf_put_n_char(' ', fm->width - len));
}
