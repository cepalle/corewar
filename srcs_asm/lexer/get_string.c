#include "asm.h"
#include "libft.h"


t_token get_string(int *i_line, char **file, int *i_col)
{
	t_token token;
	int i;
	char *tmp;
	int i_line_sav;
	int i_col_sav;

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
			tmp = token.data;
			token.data = ft_strjoin(token.data, "\n");
			free(tmp);
			tmp = token.data;
			token.data = ft_strjoin(token.data, file[*i_line]);
			free(tmp);
			continue;
		}
		(*i_col)++;
		i++;
	}
	token.data[i] = '\0';
	(*i_col)++;
	return token;
}
