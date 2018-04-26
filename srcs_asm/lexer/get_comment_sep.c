#include "asm.h"
#include "libft.h"


t_token get_separator_char(int *i_line, const char *line, int line_file)
{
	t_token token;

	(void) line_file;
	(void) line;
	ft_bzero(&token, sizeof(t_token));

	token.enum_token = TOKEN_SEPARATOR_CHAR;

	(*i_line)++;
	return (token);
};

t_token get_comment(int *i_line, const char *line, int line_file)
{
	t_token token;

	(void) line_file;
	ft_bzero(&token, sizeof(t_token));
	(*i_line)++;
	token.enum_token = TOKEN_COMMENT;
	token.data = ft_strdup(line + *i_line);
	*i_line = *i_line + (int) ft_strlen(token.data);
	return (token);
};
