#include "asm.h"
#include "op.h"
#include "libft.h"

int check_param(int ennum_token, int t_arg)
{
	if ((t_arg & T_DIR) &&
	    (ennum_token == TOKEN_DIRECT_LABEL ||
	     ennum_token == TOKEN_DIRECT_NUMBER))
		return 0;
	if ((t_arg & T_IND) &&
	    (ennum_token == TOKEN_INDIRECT_LABEL ||
	     ennum_token == TOKEN_INDIRECT_NUMBER))
		return 0;
	if ((t_arg & T_REG) &&
	    ennum_token == TOKEN_LABEL)
		return 0;
	return 1;
};

int check_cmd(t_ast_inst *inst, t_op op_desc) {
	int i;

	if (inst->nb_ast_params != op_desc.nb_arg)
		return 1;
	i = 0;
	while (i < inst->nb_ast_params)
	{
		if (check_param(inst->ast_params[i].enum_token, op_desc.args[i]))
			return 1;
		i++;
	}
	return 0;
};

int check_inst(t_ast_inst *inst)
{
	int i;

	i = 0;

	while (i < OP_TAB_LENGTH)
	{
		if (ft_strequ(gopt()[i].name, inst->cmd))
			return check_cmd(inst, gopt()[i]);
		i++;
	}
	ft_printf("error: unknow cmd: %s", inst->cmd);
	return 1;
};

int check_insts(t_ast_inst *inst)
{
	ft_printf("### check_insts\n");

	if (!inst)
		return 0;
	if (check_inst(inst))
		return 1;
	return check_insts(inst->next);
};
