#include "asm.h"
#include "libft.h"


t_token get_string(int *i_line, char **files, int *i_files)
{
	t_token token;
	int i;
	char *tmp;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_STRING;
	(*i_line)++;
	token.data = ft_strdup(files[*i_files] + *i_line);

	while (token.data[i] != '"')
	{
		if (!token.data[i])
		{
			(*i_files)++;
			*i_line = 0;
			if (!files[*i_files])
			{
				token.er = 1;
				ft_printf("lexer error: line %d: get_string, Unclosed string\n",
				          *i_line);
				return (token);
			}
			tmp = token.data;
			token.data = ft_strjoin(token.data, "\n");
			free(tmp);
			tmp = token.data;
			token.data = ft_strjoin(token.data, files[*i_files]);
			free(tmp);
			//ft_printf("%s\n", token.data);
			continue;
		}
		(*i_line)++;
		i++;
	}
	token.data[i] = '\0';
	//ft_printf(token.data);
	(*i_line)++;
	return token;
};

