#include "asm.h"
#include "libft.h"
#include "op.h"

t_token get_label(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	(void) line_file;
	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_LABEL;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (line[*i_line + i] == ':')
	{
		token.enum_token = TOKEN_LABEL_DECLARATION;
		(*i_line)++;
	}
	*i_line = *i_line + i;
	return (token);
};
