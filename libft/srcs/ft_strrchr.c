/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:43:53 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:43:54 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t			sup;
	unsigned char	cc;

	if (c == '\0')
		return ((char *)(s + ft_strlen(s)));
	cc = (unsigned char)c;
	sup = ft_strlen(s);
	while (sup + 1 > 0)
	{
		if (s[sup] == cc)
			return ((char *)(s + sup));
		sup--;
	}
	return (NULL);
}
