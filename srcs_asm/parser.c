#include "asm.h"
#include "libft.h"

void print_ast_inst(t_ast_inst *ast_inst)
{
	int i;

	if (!ast_inst)
		return;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		print_token(ast_inst->labels_dec[i]);
		i++;
	}
	i = 0;
	ft_printf("%s ", ast_inst->cmd);
	while (i < ast_inst->nb_ast_params)
	{
		print_token(ast_inst->ast_params[i]);
		i++;
	}
	ft_printf("\n");
	print_ast_inst(ast_inst->next);
};

void print_ast_prog(t_ast_prog ast_prog)
{
	ft_printf(".name: %s\n", ast_prog.prog_name);
	ft_printf(".comment: %s\n", ast_prog.prog_comment);
	print_ast_inst(ast_prog.ast_inst);
};

t_parser parser(t_lexer lexer_res)
{
	t_parser parser_res;
	int i;

	ft_bzero(&parser_res, sizeof(t_parser));
	i = 0;

	ft_printf("\n###PARSER\n\n");

	while (i <= lexer_res.tab_token.i && !parser_res.er)
		ast_add_next(&parser_res, lexer_res.tab_token, &i);
	print_ast_prog(parser_res.ast_prog);
	return parser_res;
};
