#include "asm.h"
#include "op.h"
#include "libft.h"

int has_octet_param(char *cmd)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, cmd))
			return gopt()[i].octet_param;
		i++;
	}
	ft_printf("has_octet_param, cmd no found\n");
	return 0;
};

int dir_size(char *cmd)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, cmd))
			return 2 + !gopt()[i].dir_size_2 * 2;
		i++;
	}
	ft_printf("dir_size, cmd no found\n");
	return 0;
};

int len_param(int enum_token, char *cmd)
{
	if (enum_token == TOKEN_INDIRECT_LABEL ||
			enum_token == TOKEN_INDIRECT_NUMBER)
		return 2;
	if (enum_token == TOKEN_LABEL)
		return 1;
	return dir_size(cmd);
};

int inst_len(t_ast_inst *ast_inst)
{
	int i;
	int len;

	i = 0;
	len = 1;
	len += has_octet_param(ast_inst->cmd);
	while (i < ast_inst->nb_ast_params)
	{
		len += len_param(ast_inst->ast_params[i].enum_token, ast_inst->cmd);
		i++;
	}
	return len;
};

void inst_feed_label(t_ast_inst *ast_inst, int pos)
{
	int i;

	if (!ast_inst)
		return;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		ast_inst->labels_dec[i].pos_octet_label = pos;
		i++;
	}
	inst_feed_label(ast_inst->next, pos + inst_len(ast_inst));
};

void ast_to_byte(t_parser parser_res)
{
	inst_feed_label(parser_res.ast_prog.ast_inst, 0);
	// write binnaire, header
};
