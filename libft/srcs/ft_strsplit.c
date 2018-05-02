/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:43:59 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 10:28:03 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	len_tabsplit(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		i++;
		while (*s && *s != c)
			s++;
	}
	return (i);
}

static size_t	strlen_c(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static size_t	strcpy_c(char *dest, char const *src, char c)
{
	size_t	j;

	j = 0;
	while (src[j] && src[j] != c)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	len_tab;
	size_t	i;

	if (!s)
		return (NULL);
	len_tab = len_tabsplit(s, c);
	if (!(tab = malloc(sizeof(char *) * (len_tab + 1))))
		return (NULL);
	tab[len_tab] = NULL;
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			tab[i] = malloc(sizeof(char) * (strlen_c(s, c) + 1));
			s += strcpy_c(tab[i], s, c);
		}
		i++;
	}
	return (tab);
}
