/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strlcat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:42:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:42:42 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t	min(size_t a, size_t b)
{
	return (a < b ? a : b);
}

static char		*ft_strncpy_aux(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i + 1 < n)
	{
		dest[i] = src[i];
		if (!src[i])
			return (dest);
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	to_return;
	size_t	len_dst;
	size_t	len_src;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	to_return = min(len_dst, size) + len_src;
	if (len_dst >= size)
		return (to_return);
	ft_strncpy_aux(dst + len_dst, src, size - len_dst);
	return (to_return);
}
