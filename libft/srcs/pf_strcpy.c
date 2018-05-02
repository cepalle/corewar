/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:04:51 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_strcpy(char *dest, const char *src)
{
	size_t	len_src;

	len_src = pf_strlen(src);
	pf_memcpy(dest, src, len_src + 1);
	return (dest);
}
