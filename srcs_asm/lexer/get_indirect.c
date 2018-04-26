#include "asm.h"
#include "libft.h"
#include "op.h"


t_token get_indirect_label(int *i_line, char **file, int *i_col)
{
	t_token token;
	int i;

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
		free(token.data);
		token.er = 1;
		print_local_error(file, i_col, i_line,
		                  "lexer: Indirect label, expected a label after ':'");
	}
	*i_col = *i_col + i;
	return (token);
};

t_token get_indirect_number(int *i_line, char **file, int *i_col)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_NUMBER;
	token.data = ft_strdup(file[*i_line] + *i_col);

	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	if (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
	{
		free(token.data);
		token.er = 1;
		print_local_error(file, i_col, i_line,
		                  "lexer: Indirect number, unexpected char");
	}
	token.data[i] = '\0';
	if (i == 1 && token.data[i] == '-')
	{
		free(token.data);
		token.er = 1;
		print_local_error(file, i_col, i_line,
		                  "lexer: Indirect number, no number found after '-'");
	}
	*i_col = *i_col + i;
	return (token);
};
