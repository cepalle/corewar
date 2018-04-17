/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_arg_not_type_to_str.c                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 12:55:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:41 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_arg_not_type_to_str(t_format *fm, va_list *ap)
{
	char	buf[2];

	(void)ap;
	buf[0] = fm->type;
	buf[1] = '\0';
	return (pf_strdup(buf));
}
