/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:44:11 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:44:12 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*to_do;

	if (!s)
		return (NULL);
	if (!(to_do = ft_strnew(len)))
		return (NULL);
	s += start;
	ft_strncpy(to_do, s, len);
	return (to_do);
}
