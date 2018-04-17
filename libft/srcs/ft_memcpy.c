/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:39:44 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:39:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n)
{
	size_t	i;
	char	*dst_bis;
	char	*src_bis;

	dst_bis = (char *)dst;
	src_bis = (char *)src;
	i = 0;
	while (i < n)
	{
		dst_bis[i] = src_bis[i];
		i++;
	}
	return (dst);
}
