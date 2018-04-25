/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_realloc.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 14:41:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 16:37:56 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *pt, int sizeold, int new_size)
{
	void	*to_do;

	if (sizeold < 0 || new_size < 0)
		return (NULL);
	if (sizeold >= new_size)
		return (pt);
	to_do = ft_memalloc((size_t)new_size);
	ft_memmove(to_do, pt, (size_t)sizeold);
	free(pt);
	return (to_do);
}
