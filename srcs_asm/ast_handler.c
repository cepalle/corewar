#include "asm.h"
#include "libft.h"

void ast_add_dote_start(t_parser *parser_res, t_tab_token tab_token, int *i)
{
		char *error_msg;

		error_msg = NULL;
    if (*i + 2 > tab_token.i)
			error_msg = "parser error: ast_add_dote_start not enough token";
    else if (tab_token.tokens[*i + 1].enum_token != TOKEN_STRING)
			error_msg = "parser error: ast_add_dote_start don't find token string";
    else if (tab_token.tokens[*i + 2].enum_token != TOKEN_EOL)
			error_msg = "parser error: ast_add_dote_start don't find token eol";
		else if (tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME &&
						 parser_res->ast_prog.prog_name)
			error_msg = "parser error: ast_add_dote_start more than one token prog_name found";
    else if (tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT &&
        parser_res->ast_prog.prog_comment)
			error_msg = "parser error: ast_add_dote_start more than one token prog_comment found";
		if (error_msg)
		{
			ft_printf("%s\n", error_msg);
			parser_res->er = 1;
		}
    else if (tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
        parser_res->ast_prog.prog_comment = ft_strdup(tab_token.tokens[*i + 1].data);
    else
        parser_res->ast_prog.prog_name = ft_strdup(tab_token.tokens[*i + 1].data);
    *i = *i + 3;
};

void ast_add_inst(t_parser *parser_res, t_tab_token tab_token, int *i)
{
    (void)parser_res;
    (void)tab_token;

	(*i)++;

};

void ast_add_next(t_parser *parser_res, t_tab_token tab_token, int *i)
{
    if (tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME ||
            tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
        ast_add_dote_start(parser_res, tab_token, i);
		else if (tab_token.tokens[*i].enum_token == TOKEN_LABEL)
			ast_add_inst(parser_res, tab_token, i);
		else if (tab_token.tokens[*i].enum_token == TOKEN_EOL)
			(*i)++;
    else
    {
        ft_printf("parser error: ast_add_next unexpected token\n");
        parser_res->er = 1;
    }
		if (parser_res->er)
		{
			// free
		}
};
