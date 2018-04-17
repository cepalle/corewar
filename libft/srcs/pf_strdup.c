/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:05:03 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:40 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*pf_strdup(const char *s1)
{
	size_t	len;
	char	*to_do;

	len = pf_strlen(s1);
	if (!(to_do = pf_strnew(len)))
		return (NULL);
	pf_strcpy(to_do, s1);
	return (to_do);
}
