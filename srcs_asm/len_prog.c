#include "asm.h"
#include "op.h"


int len_param(int enum_token, char *cmd)
{
	if (enum_token == TOKEN_INDIRECT_LABEL ||
	    enum_token == TOKEN_INDIRECT_NUMBER)
		return 2;
	if (enum_token == TOKEN_LABEL)
		return 1;
	return 2 + !get_op(cmd).dir_size_2 * 2;
};

int inst_len(t_ast_inst *ast_inst)
{
	int i;
	int len;

	i = 0;
	len = 1;
	len += get_op(ast_inst->cmd).octet_param;
	while (i < ast_inst->nb_ast_params)
	{
		len += len_param(ast_inst->ast_params[i].enum_token, ast_inst->cmd);
		i++;
	}
	return len;
};

unsigned prog_len(t_ast_inst *ast_inst)
{
	if (!ast_inst)
		return 0;
	return inst_len(ast_inst) + prog_len(ast_inst->next);
};
