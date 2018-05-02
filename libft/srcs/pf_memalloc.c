/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memalloc.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:03:10 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 10:36:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>

void	*pf_memalloc(size_t size)
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
