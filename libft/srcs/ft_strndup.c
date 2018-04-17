/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/05 15:42:24 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 17:25:27 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *str, int n)
{
	char	*to_do;

	to_do = ft_strdup(str);
	if (n < (int)ft_strlen(str))
		to_do[n] = '\0';
	return (to_do);
}
