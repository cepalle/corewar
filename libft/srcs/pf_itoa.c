/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/22 21:02:58 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/05 14:19:57 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

int				find_base(t_format *fm)
{
	int	base;

	if (fm->type == 'o')
		base = 8;
	else if (fm->type == 'X' || fm->type == 'x')
		base = 16;
	else
		base = 10;
	return (base);
}

static void		pf_utoa_aux(unsigned long long int n, char *dest, t_format *fm)
{
	char		*sav;
	char		(*ch)(unsigned c);
	unsigned	base;

	if (!n && fm->type != 'o')
		fm->flag_hash = 0;
	if (fm->type == 'X')
		ch = &pf_choose_xx_char;
	else if (fm->type == 'x')
		ch = &pf_choose_x_char;
	else
		ch = &pf_choose_ou_char;
	base = find_base(fm);
	dest[0] = '0';
	sav = dest;
	while (n)
	{
		*dest = ch(n % base);
		dest++;
		n /= base;
	}
	pf_strrev(sav);
}

char			*pf_utoa(unsigned long long int n, t_format *fm)
{
	char	*to_do;

	if (!(to_do = pf_strnew(63)))
		return (NULL);
	pf_utoa_aux(n, to_do, fm);
	return (to_do);
}

char			*pf_itoa(signed long long int n, t_format *fm)
{
	char					*to_do;
	unsigned long long int	un;

	if (!(to_do = pf_strnew(63)))
		return (NULL);
	if (n && n == -n)
	{
		to_do[0] = '-';
		un = 9223372036854775807;
		un++;
		pf_utoa_aux(un, to_do + 1, fm);
	}
	else if (n < 0)
	{
		to_do[0] = '-';
		n = -n;
		pf_utoa_aux(n, to_do + 1, fm);
	}
	else
		pf_utoa_aux(n, to_do, fm);
	return (to_do);
}
