#include "asm.h"
#include "libft.h"

void ast_add_dote_start(t_parser *parser_res, t_tab_token *tab_token, int *i)
{
    if (*i + 2 > tab_token->i)
    {
        // ERROR
    }
    if (tab_token->tokens[*i + 1] != TOKEN_STRING)
    {
        // ERROR
    }
    if (tab_token->tokens[*i + 2] != TOKEN_EOL)
    {
        // ERROR
    }
    if (tab_token->tokens[*i] == TOKEN_PROG_NAME &&
        parser_res->ast_prog.prog_name)
    {
        // ERROR
    }
    if (tab_token->tokens[*i] == TOKEN_PROG_COMMENT &&
        parser_res->ast_prog.prog_comment)
    {
        // ERROR
    }
    if (tab_token->tokens[*i] == TOKEN_PROG_COMMENT)
        parser_res->ast_prog.prog_comment = ft_strdup(tab_token->tokens[*i + 1].data); // error if empty?
    else
        parser_res->ast_prog.prog_name = ft_strdup(tab_token->tokens[*i + 1].data); // error if empty?
    *i = *i + 3;
};

void ast_add_inst(t_parser *parser_res, t_tab_token *tab_token, int *i)
{

};

void ast_add_next(t_parser *parser_res, t_tab_token *tab_token, int *i)
{
    if (tab_token->tokens[*i] == TOKEN_PROG_NAME ||
            tab_token->tokens[*i] == TOKEN_PROG_COMMENT)
        ast_add_dote_start(parser_res, tab_token, i);
    else if (tab_token->tokens[*i] == TOKEN_PROG_LABEL)
        ast_add_inst(parser_res, tab_token, i);
    else
    {
        // free
        parser_res->er = 1;
    }
    // handle error
};
