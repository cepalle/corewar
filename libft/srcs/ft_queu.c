/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_queu.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/06 10:34:09 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/07 11:21:34 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_queu_add(t_queu *q, int n)
{
	if (!q->queu)
		ft_queu_init(q);
	if (q->nb_el == q->size)
	{
		q->queu = (int *)ft_realloc(q->queu, q->size * sizeof(int),
				q->size * 2 * sizeof(int));
		q->size *= 2;
	}
	q->queu[q->nb_el] = n;
	q->nb_el++;
}

int		ft_queu_pop(t_queu *q)
{
	int res;

	if (q->nb_el == 0)
	{
		ft_printf("the queu is empty\n");
		return (INT_MIN);
	}
	res = q->queu[0];
	q->nb_el--;
	ft_memmove(q->queu, q->queu + 1, q->nb_el * sizeof(int));
	return (res);
}

char	ft_queu_is_in(t_queu *g, int n)
{
	int i;

	i = 0;
	while (i < g->nb_el)
	{
		if (g->queu[i] == n)
			return (1);
		i++;
	}
	return (0);
}

void	ft_queu_init(t_queu *q)
{
	q->size = QUEU_INIT_SIZE;
	q->nb_el = 0;
	q->queu = (int *)ft_memalloc(sizeof(int) * q->size);
}
