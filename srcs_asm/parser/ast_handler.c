#include "asm.h"
#include "libft.h"


void ast_add_next(t_parser *parser_res, t_tab_token tab_token, int *i)
{
	if (tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME ||
			tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
		ast_add_dote_start(parser_res, tab_token, i);
	else if (tab_token.tokens[*i].enum_token == TOKEN_EOL ||
					tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
		(*i)++;
	else if (tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION ||
					 tab_token.tokens[*i].enum_token == TOKEN_LABEL)
		ast_add_inst(parser_res, tab_token, i);
	else
	{
		ft_printf("parser error: ast_add_next unexpected token\n");
		ft_printf("i_tab: %d, token: %d\n", *i, tab_token.tokens[*i].enum_token);
		parser_res->er = 1;
	}
	if (parser_res->er)
	{
		// free parser_res
	}
};
