/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:39:16 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:39:20 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*to_do;
	size_t	i;

	if (!(to_do = (char *)malloc(size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		to_do[i] = 0;
		i++;
	}
	return (to_do);
}
