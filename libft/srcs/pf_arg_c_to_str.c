/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_c_to_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:00:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:15:59 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*pf_arg_c_to_str(t_format *fm, va_list *ap)
{
	unsigned char	c;
	unsigned char	buff[2];
	wchar_t			wc;
	wchar_t			*wcp;

	if (fm->lenght == 'l')
	{
		wc = (wchar_t)va_arg(*ap, unsigned int);
		wcp = (wchar_t *)malloc(1 * sizeof(wchar_t));
		*wcp = wc;
		return ((char *)wcp);
	}
	c = (unsigned char)va_arg(*ap, unsigned int);
	buff[0] = c;
	buff[1] = '\0';
	return (pf_strdup((char *)buff));
}
