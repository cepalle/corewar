/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   pf_put_wc.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/27 14:34:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:20:34 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static int	put_size_faur(wchar_t cc)
{
	unsigned char	o;

	o = (cc >> 18) + (0b11110000);
	pf_putchar(o);
	o = ((cc >> 12) & 0b00111111) + (0b10000000);
	pf_putchar(o);
	o = ((cc >> 6) & 0b00111111) + (0b10000000);
	pf_putchar(o);
	o = (cc & 0b00111111) + (0b10000000);
	pf_putchar(o);
	return (4);
}

static int	put_size_three(wchar_t cc)
{
	unsigned char	o;

	o = (cc >> 12) + (0b11100000);
	pf_putchar(o);
	o = ((cc >> 6) & 0b00111111) + (0b10000000);
	pf_putchar(o);
	o = (cc & 0b00111111) + (0b10000000);
	pf_putchar(o);
	return (3);
}

int			pf_put_wc(wchar_t cc)
{
	unsigned char	o;

	if (!(cc >> 7))
	{
		pf_putchar(cc);
		return (1);
	}
	else if (!(cc >> 11))
	{
		o = (cc >> 6) + (0b11000000);
		pf_putchar(o);
		o = (cc & 0b00111111) + (0b10000000);
		pf_putchar(o);
		return (2);
	}
	else if (!(cc >> 16))
		return (put_size_three(cc));
	else
		return (put_size_faur(cc));
}
