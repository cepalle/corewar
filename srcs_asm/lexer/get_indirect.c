/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_indirect.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:37 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

t_token	get_indirect_label(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_LABEL;
	(*i_col)++;
	token.data = ft_strdup(file[*i_line] + *i_col);
	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (!ft_strlen(token.data))
	{
		token.er = 1;
		print_local_error(file, i_col, i_line,
						"lexer: Indirect label, expected a label after ':'");
	}
	*i_col = *i_col + i;
	return (token);
}

void	check_indirect_number(t_token *token, int i, t_file cfile)
{
	if (i == 1 && token->data[0] == '-')
	{
		token->er = 1;
		print_local_error(cfile.file, cfile.i_col, cfile.i_line,
						"lexer: Direct_number, no number found after '-'");
		return ;
	}
	if (token->data[i] && ft_strchr(LABEL_CHARS, token->data[i]))
	{
		token->er = 1;
		print_local_error(cfile.file, cfile.i_col, cfile.i_line,
						"lexer: Direct number, unexpected char");
		return ;
	}
}

t_token	get_indirect_number(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;
	t_file	cfile;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	cfile.file = file;
	cfile.i_col = i_col;
	cfile.i_line = i_line;
	token.enum_token = TOKEN_INDIRECT_NUMBER;
	token.data = ft_strdup(file[*i_line] + *i_col);
	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	check_indirect_number(&token, i, cfile);
	token.data[i] = '\0';
	*i_col = *i_col + i;
	return (token);
}
