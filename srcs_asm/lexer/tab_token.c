/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   tab_token.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:39:14 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:39:15 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	init_tab_token(t_tab_token *tab_token)
{
	tab_token->len = TAB_TOKEN_LEN_INIT;
	tab_token->i = -1;
	tab_token->tokens = ft_memalloc(sizeof(t_token) * tab_token->len);
}

void	tab_token_add(t_tab_token *tab_token, t_token tken)
{
	if (!tab_token->tokens)
		init_tab_token(tab_token);
	tab_token->i++;
	if (tab_token->i >= tab_token->len)
	{
		tab_token->tokens = ft_realloc(tab_token->tokens,
		sizeof(t_token) * tab_token->len, sizeof(t_token) * tab_token->len * 2);
		tab_token->len = tab_token->len * 2;
	}
	tab_token->tokens[tab_token->i] = tken;
}

void	tab_token_multi_add(t_tab_token *tab_token, t_token *ltken)
{
	int	i;

	if (!tab_token->tokens)
		init_tab_token(tab_token);
	i = 0;
	while (1)
	{
		tab_token_add(tab_token, ltken[i]);
		if (ltken[i].enum_token == TOKEN_EOL)
			break ;
		i++;
	}
}
