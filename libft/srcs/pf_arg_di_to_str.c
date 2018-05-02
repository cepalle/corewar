/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_di_to_str.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:01:04 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:40 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_arg_di_to_str(t_format *fm, va_list *ap)
{
	signed long long nb;

	if (fm->lenght == 'H')
		nb = (signed char)va_arg(*ap, signed int);
	else if (fm->lenght == 'h')
		nb = (signed short)va_arg(*ap, signed int);
	else if (fm->lenght == 'l')
		nb = (signed long int)va_arg(*ap, signed long int);
	else if (fm->lenght == 'L')
		nb = (signed long long int)va_arg(*ap, signed long long int);
	else if (fm->lenght == 'j')
		nb = (intmax_t)va_arg(*ap, intmax_t);
	else if (fm->lenght == 'z')
		nb = (ssize_t)va_arg(*ap, ssize_t);
	else
		nb = (signed int)va_arg(*ap, signed int);
	return (pf_itoa(nb, fm));
}
