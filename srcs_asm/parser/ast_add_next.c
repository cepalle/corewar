#include "asm.h"
#include "libft.h"


void ast_add_next(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
		ast_add_dote_start(parser_res, lexer_res, i);
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_EOL ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
		(*i)++;
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION ||
			lexer_res.tab_token.tokens[*i].enum_token == TOKEN_LABEL)
		ast_add_inst(parser_res, lexer_res, i);
	else
	{
	    print_local_error(lexer_res.file, &(lexer_res.tab_token.tokens[*i].file_pose_col),
                          &(lexer_res.tab_token.tokens[*i].file_pose_line),
        "parser: Unexpected token");
		parser_res->er = 1;
	}
	if (parser_res->er)
	{
		// free parser_res
	}
}
