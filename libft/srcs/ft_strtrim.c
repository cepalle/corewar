/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/04 10:44:17 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/04 10:44:18 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int		is_space(char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

static size_t	nb_space_start(char const *str)
{
	size_t	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}

static size_t	nb_space_end(char const *str)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = 0;
	while (i < len && is_space(str[len - 1 - i]))
		i++;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	size_t	len;
	size_t	start;
	size_t	space_end;
	char	*ss;

	if (!s)
		return (NULL);
	ss = (char *)s;
	len = ft_strlen(s);
	start = nb_space_start(s);
	space_end = nb_space_end(s);
	if (start + space_end >= len)
		return (ft_strnew(0));
	return (ft_strsub(ss, start, len - start - space_end));
}
