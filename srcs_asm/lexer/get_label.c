/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_label.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:44 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:45 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

t_token	get_label(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_LABEL;
	token.data = ft_strdup(file[*i_line] + *i_col);
	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (file[*i_line][*i_col + i] == ':')
	{
		token.enum_token = TOKEN_LABEL_DECLARATION;
		(*i_col)++;
	}
	*i_col = *i_col + i;
	return (token);
}
