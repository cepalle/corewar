/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   swap_char.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 11:30:42 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 11:30:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

static void	swap_char(unsigned char *a, unsigned char *b)
{
	unsigned char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void		swap_2(unsigned short int *to_swap)
{
	unsigned char	*pt;

	pt = (unsigned char *)to_swap;
	swap_char(pt, pt + 1);
}

void		swap_4(unsigned int *to_swap)
{
	unsigned char	*pt;

	pt = (unsigned char *)to_swap;
	swap_char(pt, pt + 3);
	swap_char(pt + 1, pt + 2);
}
