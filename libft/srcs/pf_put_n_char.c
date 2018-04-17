/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   put_n_char.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:07:23 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:32 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

int		pf_put_n_char(char c, int nb)
{
	int length;

	length = 0;
	while (nb > 0)
	{
		pf_putchar(c);
		nb--;
		length++;
	}
	return (length);
}
