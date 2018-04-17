/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_strrev.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/28 15:09:58 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*pf_strrev(char *str)
{
	size_t	sup;
	size_t	inf;
	char	tmp;

	inf = 0;
	if (!str || !*str)
		return (str);
	sup = pf_strlen(str) - 1;
	while (inf < sup)
	{
		tmp = str[inf];
		str[inf] = str[sup];
		str[sup] = tmp;
		inf++;
		sup--;
	}
	return (str);
}
