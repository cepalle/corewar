/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_wstrlen.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 15:36:21 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	pf_size_wc(wchar_t wc)
{
	if (!(wc >> 7))
		return (1);
	if (!(wc >> 11))
		return (2);
	if (!(wc >> 16))
		return (3);
	return (4);
}

int	pf_wstrlen(wchar_t *wstr)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (wstr[i])
	{
		len += pf_size_wc(wstr[i]);
		i++;
	}
	return (len);
}
