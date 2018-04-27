#include "asm.h"
#include "libft.h"

t_parser parser(t_lexer lexer_res)
{
	t_parser parser_res;
	int i;

	ft_bzero(&parser_res, sizeof(t_parser));
	i = 0;

	//ft_printf("\n###PARSER\n\n");

	while (i <= lexer_res.tab_token.i && !parser_res.er)
		ast_add_next(&parser_res, lexer_res, &i);

	if (parser_res.er || check_ast(parser_res, lexer_res.file))
	{
		//free
		parser_res.er = 1;
	}
	return parser_res;
}
