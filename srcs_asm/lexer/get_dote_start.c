#include "asm.h"
#include "libft.h"

t_token get_dote_start(int *i_line, const char *line, int line_file)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));

	if (ft_strnequ(".name", line + *i_line, 5))
	{
		token.enum_token = TOKEN_PROG_NAME;
		*i_line = *i_line + 5;
		return token;
	}
	if (ft_strnequ(".comment", line + *i_line, 8))
	{
		token.enum_token = TOKEN_PROG_COMMENT;
		*i_line = *i_line + 8;
		return token;
	}
	ft_printf(
			"lexer error: line %d: get_dote_start, Unexpected token after '.'\n",
			line_file);
	token.er = 1;
	return (token);
};

