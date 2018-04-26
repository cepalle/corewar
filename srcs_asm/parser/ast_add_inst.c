#include "asm.h"
#include "libft.h"

void inst_add_labels_dec(t_ast_inst *ast_inst, t_tab_token tab_token, int *i)
{
	while (tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION &&
	       !ast_inst->er)
	{
		if (ast_inst->nb_labels_dec >= LABELS_DEC_LEN)
		{
			ft_printf("paser error: inst_add_labels_dec too many label\n");
			ast_inst->er = 1;
			// free inst
			return;
		}
		ast_inst->labels_dec[ast_inst->nb_labels_dec] = tab_token.tokens[*i];
		ast_inst->labels_dec[ast_inst->nb_labels_dec].data = ft_strdup(
				tab_token.tokens[*i].data);
		ast_inst->nb_labels_dec++;
		(*i)++;
		while (tab_token.tokens[*i].enum_token == TOKEN_EOL ||
		       tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
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

void ast_add_inst_aux(t_parser *parser_res, t_ast_inst ast_inst)
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

void ast_add_inst(t_parser *parser_res,  t_lexer lexer_res, int *i)
{
	t_ast_inst ast_inst;

	ft_bzero(&ast_inst, sizeof(ast_inst));
	inst_add_labels_dec(&ast_inst, lexer_res.tab_token, i);
	if (ast_inst.er)
	{
		parser_res->er = 1;
		return;
	}
	if (ast_inst.nb_labels_dec > 0 && lexer_res.tab_token.i < (*i))
	{
		//ft_printf("cmd empty add\n");
		print_token(lexer_res.tab_token.tokens[*i]);
		ast_add_inst_aux(parser_res, ast_inst);
		return;
	};
	if (lexer_res.tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
		ft_printf("paser error: ast_add_inst label not found\n");
		print_token(lexer_res.tab_token.tokens[*i]);
		ft_printf("\n");
		parser_res->er = 1;
		// free inst
		return;
	}
	ast_inst.cmd = ft_strdup(lexer_res.tab_token.tokens[*i].data);
	(*i)++;
	inst_add_params(&ast_inst, lexer_res.tab_token, i);
	if (ast_inst.er)
		parser_res->er = 1;
	ast_add_inst_aux(parser_res, ast_inst);
};
