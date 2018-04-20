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
		parser_res->ast_prog.prog_comment = ft_strdup(
						tab_token.tokens[*i + 1].data);
	else
		parser_res->ast_prog.prog_name = ft_strdup(tab_token.tokens[*i + 1].data);
	*i = *i + 3;
};

void inst_add_labels_dec(t_ast_inst *ast_inst, t_tab_token tab_token, int *i)
{
	while (tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION &&
				 !ast_inst->er)
	{
		if (ast_inst->nb_labels_dec >= LABELS_DEC_LEN)
		{
			ft_printf("paser error: inst_add_labels_dec label not found\n");
			ast_inst->er = 1;
			// free inst
			return;
		}
		ast_inst->labels_dec[ast_inst->nb_labels_dec] = tab_token.tokens[*i];
		ast_inst->labels_dec[ast_inst->nb_labels_dec].data = ft_strdup(
						tab_token.tokens[*i].data);
		ast_inst->nb_labels_dec++;
		(*i)++;
		while (tab_token.tokens[*i].enum_token == TOKEN_EOL)
			(*i)++;
	}
};

void inst_add_params(t_ast_inst *ast_inst, t_tab_token tab_token, int *i)
{
	if (tab_token.tokens[*i].enum_token != TOKEN_DIRECT_LABEL &&
			tab_token.tokens[*i].enum_token != TOKEN_DIRECT_NUMBER &&
			tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_NUMBER &&
			tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_LABEL &&
			tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
		ft_printf("paser error: inst_add_params not a excepted label\n");
		ast_inst->er = 1;
		// free inst
		return;
	}
	if (ast_inst->nb_ast_params >= MAX_PARAMS)
	{
		ft_printf("paser error: inst_add_params too many params\n");
		ast_inst->er = 1;
		// free inst
		return;
	}
	ast_inst->ast_params[ast_inst->nb_ast_params] = tab_token.tokens[*i];
	ast_inst->ast_params[ast_inst->nb_ast_params].data = ft_strdup(
					tab_token.tokens[*i].data);
	ast_inst->nb_ast_params++;
	(*i)++;
	if (tab_token.tokens[*i].enum_token == TOKEN_SEPARATOR_CHAR)
	{
		(*i)++;
		inst_add_params(ast_inst, tab_token, i);
	}
};

void add_inst_pareser_res(t_parser *parser_res, t_ast_inst ast_inst)
{
	t_ast_inst *current;
	t_ast_inst *to_add;
	to_add = ft_memalloc(sizeof(t_ast_inst));
	*to_add = ast_inst;

	if (!parser_res->ast_prog.ast_inst)
		parser_res->ast_prog.ast_inst = to_add;
	else
	{
		current = parser_res->ast_prog.ast_inst;
		while (current->next)
			current = current->next;
		current->next = to_add;
	}
}

void ast_add_inst(t_parser *parser_res, t_tab_token tab_token, int *i)
{
	t_ast_inst ast_inst;

	ft_bzero(&ast_inst, sizeof(ast_inst));
	inst_add_labels_dec(&ast_inst, tab_token, i);
	if (ast_inst.er)
	{
		parser_res->er = 1;
		return;
	}
	if (tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
		ft_printf("paser error: ast_add_inst label not found\n");
		parser_res->er = 1;
		// free inst
		return;
	}
	ast_inst.cmd = ft_strdup(tab_token.tokens[*i].data);
	(*i)++;
	inst_add_params(&ast_inst, tab_token, i);
	if (ast_inst.er)
		parser_res->er = 1;
	add_inst_pareser_res(parser_res, ast_inst);
};

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
