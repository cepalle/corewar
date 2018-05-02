/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_direct.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:19 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:21 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

void	check_direct_number(t_token *token, int i, t_file cfile)
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

t_token	get_direct_number(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;
	t_file	cfile;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	cfile.file = file;
	cfile.i_col = i_col;
	cfile.i_line = i_line;
	token.enum_token = TOKEN_DIRECT_NUMBER;
	token.data = ft_strdup(file[*i_line] + *i_col);
	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	check_direct_number(&token, i, cfile);
	token.data[i] = '\0';
	*i_col = *i_col + i;
	return (token);
}

t_token	get_direct_label(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_DIRECT_LABEL;
	(*i_col)++;
	token.data = ft_strdup(file[*i_line] + *i_col);
	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (!ft_strlen(token.data))
	{
		token.er = 1;
		print_local_error(file, i_col, i_line,
						"lexer: Direct label, unexpected char after ':'");
	}
	*i_col = *i_col + i;
	return (token);
}

t_token	get_direct(int *i_line, char **file, int *i_col)
{
	t_token	token;

	(*i_col)++;
	ft_bzero(&token, sizeof(t_token));
	if (file[*i_line][*i_col] == ':')
		token = get_direct_label(i_line, file, i_col);
	else if (ft_isdigit(file[*i_line][*i_col]) ||
		file[*i_line][*i_col] == '-')
		token = get_direct_number(i_line, file, i_col);
	else
	{
		token.er = 1;
		print_local_error(file, i_col, i_line,
						"lexer: excepted ':' or digit");
	}
	return (token);
}
