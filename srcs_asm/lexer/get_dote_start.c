/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_dote_start.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:31 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

t_token	get_dote_start(int *i_line, char **file, int *i_col)
{
	t_token	token;

	ft_bzero(&token, sizeof(t_token));
	if (ft_strnequ(".name", file[*i_line] + *i_col, 5))
	{
		token.enum_token = TOKEN_PROG_NAME;
		*i_col = *i_col + 5;
		return (token);
	}
	if (ft_strnequ(".comment", file[*i_line] + *i_col, 8))
	{
		token.enum_token = TOKEN_PROG_COMMENT;
		*i_col = *i_col + 8;
		return (token);
	}
	print_local_error(file, i_col, i_line,
					"lexer: Dote start, unexpected word after '.'");
	token.er = 1;
	return (token);
}
