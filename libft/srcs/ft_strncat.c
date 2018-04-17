/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:43:19 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:43:20 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *restrict s1, const char *restrict s2, size_t n)
{
	size_t	i;
	char	*ss1;

	ss1 = s1;
	ss1 += ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		ss1[i] = s2[i];
		i++;
	}
	ss1[i] = '\0';
	return (s1);
}
