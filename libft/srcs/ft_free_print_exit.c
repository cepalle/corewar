/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_free_print_exit.c                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 11:26:17 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 11:26:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_free_print_exit(void *pt, char *str, int n)
{
	if (pt)
		free(pt);
	if (str)
		ft_printf("%s\n", str);
	exit(n);
}
