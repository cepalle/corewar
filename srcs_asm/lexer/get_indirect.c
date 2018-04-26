#include "asm.h"
#include "libft.h"
#include "op.h"


t_token get_indirect_label(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_LABEL;
	(*i_line)++;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (!ft_strlen(token.data))
	{
		free(token.data);
		token.er = 1;
		ft_printf(
				"lexer error: line %d: get_indirect_label expected label after ':'\n",
				line_file);
	}
	*i_line = *i_line + i;
	return (token);
};

t_token get_indirect_number(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_NUMBER;
	token.data = ft_strdup(line + *i_line);

	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	if (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
	{
		free(token.data);
		token.er = 1;
		ft_printf(
				"lexer error: line %d: get_indirect_number, Unexpected token\n",
				line_file);
	}
	token.data[i] = '\0';
	if (i == 1 && token.data[i] == '-')
	{
		free(token.data);
		token.er = 1;
		ft_printf(
				"lexer error: line %d: get_indirect_number, no number found after '-'\n",
				line_file);
	}
	*i_line = *i_line + i;
	return (token);
};
