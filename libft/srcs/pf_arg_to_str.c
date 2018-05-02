/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   arg_to_str.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:02:05 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_arg_to_str(t_format *fm, va_list *ap)
{
	if (fm->type == 'd' || fm->type == 'i')
		return (pf_arg_di_to_str(fm, ap));
	else if (fm->type == 'o' || fm->type == 'u' ||
			fm->type == 'x' || fm->type == 'X')
		return (pf_arg_oux_to_str(fm, ap));
	else if (fm->type == 'p')
		return (pf_arg_p_to_str(fm, ap));
	else if (fm->type == 's')
		return (pf_arg_s_to_str(fm, ap));
	else if (fm->type == '%')
		return (pf_not_arg_to_str(fm, ap));
	else if (fm->type == 'c')
		return (pf_arg_c_to_str(fm, ap));
	else if (fm->type)
		return (pf_arg_not_type_to_str(fm, ap));
	return (pf_strnew(0));
}
