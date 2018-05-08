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

char	*get_string_file(int *i_line, char **file, int *i_col)
{
	char	*string;
	int		i;

	i = 0;
	string = ft_strdup(file[*i_line] + *i_col);
	while (string[i] != '"')
	{
		if (!string[i])
		{
			(*i_line)++;
			*i_col = 0;
			if (!file[*i_line])
			{
				free(string);
				return (NULL);
			}
			string = join_new_line(string, file[*i_line]);
			continue ;
		}
		(*i_col)++;
		i++;
	}
	string[i] = '\0';
	return (string);
}

t_token	get_string(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i_line_sav;
	int		i_col_sav;

	i_line_sav = *i_line;
	i_col_sav = *i_col;
	ft_bzero(&token, sizeof(t_token));
	token.enum_token = TOKEN_STRING;
	(*i_col)++;
	token.data = get_string_file(i_line, file, i_col);
	if (!token.data)
	{
		token.er = 1;
		print_local_error(file, &(i_col_sav), &(i_line_sav),
			"lexer: Unclosed string");
		return (token);
	}
	(*i_col)++;
	return (token);
}
