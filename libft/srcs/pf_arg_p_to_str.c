/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_p_to_str.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 20:58:32 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_arg_p_to_str(t_format *fm, va_list *ap)
{
	unsigned long int	p;
	char				*str;

	p = (unsigned long int)va_arg(*ap, void *);
	fm->type = 'x';
	str = pf_utoa(p, fm);
	fm->type = 'p';
	return (str);
}
