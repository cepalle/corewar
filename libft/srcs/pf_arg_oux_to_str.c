/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_ouxX_to_str.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:01:22 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:42 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_arg_oux_to_str(t_format *fm, va_list *ap)
{
	unsigned long long int	nb;

	if (fm->lenght == 'H')
		nb = (unsigned char)va_arg(*ap, unsigned int);
	else if (fm->lenght == 'h')
		nb = (unsigned short)va_arg(*ap, unsigned int);
	else if (fm->lenght == 'l')
		nb = (unsigned long int)va_arg(*ap, unsigned long int);
	else if (fm->lenght == 'L')
		nb = (unsigned long long int)va_arg(*ap, unsigned long long int);
	else if (fm->lenght == 'j')
		nb = (uintmax_t)va_arg(*ap, uintmax_t);
	else if (fm->lenght == 'z')
		nb = (size_t)va_arg(*ap, size_t);
	else
		nb = (unsigned int)va_arg(*ap, unsigned int);
	return (pf_utoa(nb, fm));
}
