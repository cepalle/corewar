#include "libft.h"
#include "asm.h"

int check_label_if_exist(t_ast_inst *ast_inst, const char *to_find)
{
	int i;

	if (!ast_inst)
		return 1;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ft_strequ(to_find, ast_inst->labels_dec[i].data))
			return 0;
		i++;
	}
	return check_label_if_exist(ast_inst->next, to_find);
}

int check_labels(t_parser parser_res, t_ast_inst *ast_inst, char **file)
{
	int i;

	//ft_printf("### check_labels\n");

	if (!ast_inst)
		return 0;
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if ((ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL ||
		     ast_inst->ast_params[i].enum_token == TOKEN_INDIRECT_LABEL) &&
		    check_label_if_exist(parser_res.ast_prog.ast_inst, ast_inst->ast_params[i].data))
		{
			ft_printf("label is not declare '%s'\n", ast_inst->ast_params[i].data);
			return 1;
		}
		i++;
	}
	return check_labels(parser_res, ast_inst->next, file);
}
