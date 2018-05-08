/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   input_free.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/03 09:52:54 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/03 09:52:56 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "corewar.h"
#include "libft.h"

void	input_free(t_input *input)
{
	unsigned int a;

	a = 0;
	while (a < input->nb_p)
	{
		free(input->prog[a]);
		a++;
	}
}
