/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:39:10 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:39:12 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_strrev(char *str)
{
	size_t	sup;
	size_t	inf;
	char	tmp;

	inf = 0;
	if (!str || !*str)
		return (str);
	sup = ft_strlen(str) - 1;
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

static void		ft_itoa_aux(int n, char *dest)
{
	char *sav;

	sav = dest;
	while (n)
	{
		*dest = n % 10 + '0';
		dest++;
		n /= 10;
	}
	ft_strrev(sav);
}

static size_t	leni(int n)
{
	size_t	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char	*to_do;
	size_t	i;

	i = 0;
	if (!(to_do = ft_strnew(leni(n))))
		return (NULL);
	to_do[0] = '0';
	if (n == -2147483648)
	{
		to_do[i++] = '-';
		to_do[i++] = '2';
		n = 147483648;
	}
	else if (n < 0)
	{
		to_do[i++] = '-';
		n = -n;
	}
	ft_itoa_aux(n, to_do + i);
	return (to_do);
}
