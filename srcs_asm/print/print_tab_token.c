/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   print_tab_token.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:41:59 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:42:00 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	print_token(t_token token)
{
	if (token.enum_token == TOKEN_PROG_NAME)
		ft_printf(".name ");
	if (token.enum_token == TOKEN_PROG_COMMENT)
		ft_printf(".comment ");
	if (token.enum_token == TOKEN_DIRECT_LABEL)
		ft_printf("%%:%s ", token.data);
	if (token.enum_token == TOKEN_DIRECT_NUMBER)
		ft_printf("%%%s ", token.data);
	if (token.enum_token == TOKEN_INDIRECT_NUMBER)
		ft_printf("%s ", token.data);
	if (token.enum_token == TOKEN_INDIRECT_LABEL)
		ft_printf(":%s ", token.data);
	if (token.enum_token == TOKEN_LABEL_DECLARATION)
		ft_printf("%s: ", token.data);
	if (token.enum_token == TOKEN_LABEL)
		ft_printf("%s ", token.data);
	if (token.enum_token == TOKEN_STRING)
		ft_printf("'%s' ", token.data);
	if (token.enum_token == TOKEN_COMMENT)
		ft_printf("#%s ", token.data);
	if (token.enum_token == TOKEN_SEPARATOR_CHAR)
		ft_printf(", ");
	if (token.enum_token == TOKEN_EOL)
		ft_printf("\n");
}

void	print_tab_token(t_tab_token tab_token)
{
	int	i;

	i = 0;
	if (tab_token.i < 0)
		return ;
	while (i <= tab_token.i)
	{
		print_token(tab_token.tokens[i]);
		i++;
	}
}
