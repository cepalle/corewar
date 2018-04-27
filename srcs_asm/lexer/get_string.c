#include "asm.h"
#include "libft.h"


t_token get_string(int *i_line, char **file, int *i_col)
{
	t_token token;
	int i;
	char *tmp;

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

				print_local_error(file, i_col, i_line,
				                  "lexer: Unclosed string");
				return (token);
			}
			tmp = token.data;
			token.data = ft_strjoin(token.data, "\n");
			free(tmp);
			tmp = token.data;
			token.data = ft_strjoin(token.data, file[*i_line]);
			free(tmp);
			//ft_printf("%s\n", token.data);
			continue;
		}
		(*i_col)++;
		i++;
	}
	token.data[i] = '\0';
	//ft_printf(token.data);
	(*i_col)++;
	return token;
}
