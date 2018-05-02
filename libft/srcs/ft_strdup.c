/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:42:11 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 15:38:37 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*to_do;

	len = ft_strlen(s1);
	if (!(to_do = ft_strnew(len)))
		return (NULL);
	ft_strcpy(to_do, s1);
	return (to_do);
}
