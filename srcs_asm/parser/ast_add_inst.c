#include "asm.h"
#include "libft.h"

void inst_add_labels_dec(t_ast_inst *ast_inst, t_lexer lexer_res, int *i)
{
	while (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_LABEL_DECLARATION &&
	       !ast_inst->er)
	{
		if (ast_inst->nb_labels_dec + 1 >= LABELS_DEC_LEN)
		{
		    print_local_error(lexer_res.file, &(lexer_res.tab_token.tokens[*i].file_pose_col),
                              &(lexer_res.tab_token.tokens[*i].file_pose_line),
                              "paser: Too many label befor one cmd");
			ast_inst->er = 1;
			return;
		}
		ast_inst->labels_dec[ast_inst->nb_labels_dec] = lexer_res.tab_token.tokens[*i];
		ast_inst->labels_dec[ast_inst->nb_labels_dec].data = ft_strdup(
                lexer_res.tab_token.tokens[*i].data);
		ast_inst->nb_labels_dec++;
		(*i)++;
		while (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_EOL ||
                lexer_res.tab_token.tokens[*i].enum_token == TOKEN_COMMENT)
			(*i)++;
	}
}

void inst_add_params(t_ast_inst *ast_inst, t_lexer lexer_res, int *i)
{
	if (lexer_res.tab_token.tokens[*i].enum_token != TOKEN_DIRECT_LABEL &&
            lexer_res.tab_token.tokens[*i].enum_token != TOKEN_DIRECT_NUMBER &&
            lexer_res.tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_NUMBER &&
            lexer_res.tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_LABEL &&
            lexer_res.tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
        print_local_error(lexer_res.file, &(lexer_res.tab_token.tokens[*i].file_pose_col),
                          &(lexer_res.tab_token.tokens[*i].file_pose_line),
                          "parser: Need a param");
		ast_inst->er = 1;
		return;
	}
	if (ast_inst->nb_ast_params >= MAX_PARAMS)
	{
        print_local_error(lexer_res.file, &(lexer_res.tab_token.tokens[*i].file_pose_col),
                          &(lexer_res.tab_token.tokens[*i].file_pose_line),
                          "parser: command can't have more than 3 param");
		ast_inst->er = 1;
		return;
	}
	ast_inst->ast_params[ast_inst->nb_ast_params] = lexer_res.tab_token.tokens[*i];
	ast_inst->ast_params[ast_inst->nb_ast_params].data = ft_strdup(
            lexer_res.tab_token.tokens[*i].data);
	ast_inst->nb_ast_params++;
	(*i)++;
	if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_SEPARATOR_CHAR)
	{
		(*i)++;
		inst_add_params(ast_inst, lexer_res, i);
	}
}

void add_inst_to_parser_res(t_parser *parser_res, t_ast_inst ast_inst)
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

void ast_add_inst(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	t_ast_inst ast_inst;

	ft_bzero(&ast_inst, sizeof(t_ast_inst));
	inst_add_labels_dec(&ast_inst, lexer_res, i);
	if (ast_inst.er)
	{
		parser_res->er = 1;
		add_inst_to_parser_res(parser_res, ast_inst);
		return;
	}
	if (ast_inst.nb_labels_dec > 0 && lexer_res.tab_token.i < (*i))
	{
		print_token(lexer_res.tab_token.tokens[*i]);
		add_inst_to_parser_res(parser_res, ast_inst);
		return;
	};
	if (lexer_res.tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
	    print_local_error(lexer_res.file, &(lexer_res.tab_token.tokens[*i].file_pose_col),
                          &(lexer_res.tab_token.tokens[*i].file_pose_line),
                          "parser: Need a command");
		ft_printf("\n");
		parser_res->er = 1;
		add_inst_to_parser_res(parser_res, ast_inst);
		return;
	}
	ast_inst.cmd = lexer_res.tab_token.tokens[*i];
	ast_inst.cmd.data = ft_strdup(lexer_res.tab_token.tokens[*i].data);
	(*i)++;
	inst_add_params(&ast_inst, lexer_res, i);
	if (ast_inst.er)
		parser_res->er = 1;
	add_inst_to_parser_res(parser_res, ast_inst);
}
