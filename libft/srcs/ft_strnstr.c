/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strnstr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:43:48 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:43:49 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strncmp_aux(const char *s1, const char *s2, size_t n,
		size_t len)
{
	size_t			i;
	unsigned char	*ss1;
	unsigned char	*ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (i >= len)
			return (1);
		if (!ss1[i] || ss1[i] != ss2[i])
			return (ss1[i] - ss2[i]);
		i++;
	}
	return (0);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && len)
	{
		if (!ft_strncmp_aux(haystack, needle, ft_strlen(needle), len))
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
