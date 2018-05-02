/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_string.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:38:50 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:38:52 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

char	*join_new_line(char *data, char *new_line)
{
	char	*tmp;

	tmp = data;
	data = ft_strjoin(data, "\n");
	free(tmp);
	tmp = data;
	data = ft_strjoin(data, new_line);
	free(tmp);
	return (data);
}

t_token	get_string(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i;
	int		i_line_sav;
	int		i_col_sav;

	i_line_sav = *i_line;
	i_col_sav = *i_col;
	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_STRING;
	(*i_col)++;
	token.data = ft_strdup(file[*i_line] + *i_col);
	while (token.data[i] != '"')
	{
		if (!token.data[i])
		{
			(*i_line)++;
			*i_col = 0;
			if (!file[*i_line])
			{
				token.er = 1;
				print_local_error(file, &(i_col_sav), &(i_line_sav),
				"lexer: Unclosed string");
				return (token);
			}
			token.data = join_new_line(token.data, file[*i_line]);
			continue ;
		}
		(*i_col)++;
		i++;
	}
	token.data[i] = '\0';
	(*i_col)++;
	return (token);
}
