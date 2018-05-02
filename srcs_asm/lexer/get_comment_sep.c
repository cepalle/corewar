/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_comment_sep.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:11 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:13 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_token	get_separator_char(int *i_line, char **file, int *i_col)
{
	t_token token;

	(void)i_line;
	(void)file;
	ft_bzero(&token, sizeof(t_token));
	token.enum_token = TOKEN_SEPARATOR_CHAR;
	(*i_col)++;
	return (token);
}

t_token	get_comment(int *i_line, char **file, int *i_col)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));
	(*i_col)++;
	token.enum_token = TOKEN_COMMENT;
	token.data = ft_strdup(file[*i_line] + *i_col);
	*i_col = *i_col + (int)ft_strlen(token.data);
	return (token);
}
