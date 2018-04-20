#include "asm.h"
#include "libft.h"

t_parser parser(t_lexer lexer_res)
{
	t_parser parser_res;
	int i;

	ft_bzero(&parser_res, sizeof(t_parser));
	i = 0;

	ft_printf("\n###PARSER\n\n");

	while (i <= lexer_res.tab_token.i && !parser_res.er)
		ast_add_next(&parser_res, &(lexer_res.tab_token), &i);
	return parser_res;
};
