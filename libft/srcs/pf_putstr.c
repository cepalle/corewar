/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:04:35 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:36 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int	pf_putstr(char const *s)
{
	int i;

	i = 0;
	while (*s)
	{
		pf_putchar(*s);
		s++;
		i++;
	}
	return (i);
}
