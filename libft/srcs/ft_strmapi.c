/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strmapi.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:43:03 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:43:05 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*to_do;

	if (!s || !f)
		return (NULL);
	i = 0;
	len = ft_strlen(s);
	if (!(to_do = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		to_do[i] = f((unsigned int)i, s[i]);
		i++;
	}
	return (to_do);
}
