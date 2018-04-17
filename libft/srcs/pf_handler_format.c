/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_handler_format.c                              .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 16:01:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:51 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	pf_handler_format(t_format *fm)
{
	(void)fm;
	if (fm->flag_minus)
		fm->flag_0 = 0;
	if ((fm->type == 'd' || fm->type == 'i' || fm->type == 'o' ||
			fm->type == 'u' || fm->type == 'x' || fm->type == 'X')
			&& fm->precision >= 0)
		fm->flag_0 = 0;
}
