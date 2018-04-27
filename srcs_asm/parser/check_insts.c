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
	ft_printf("bad parameter\n");
	return 1;
}

int check_cmd(t_ast_inst *inst, t_op op_desc)
{
	int i;

	if (inst->nb_ast_params != op_desc.nb_arg)
	{
		ft_printf("bad number of param for cmd %s\n", op_desc.name);
		return 1;
	}
	i = 0;
	while (i < inst->nb_ast_params)
	{
		if (check_param(inst->ast_params[i].enum_token, op_desc.args[i]))
			return 1;
		i++;
	}
	return 0;
}

int check_inst(t_ast_inst *inst, char **file)
{
	int i;

	i = 0;
	if (!inst->nb_labels_dec && !inst->cmd.enum_token)
	{
		ft_printf("Unexpected error: 1\n");
		return 1;
	}
	if (!inst->cmd.enum_token && inst->next)
	{
		print_local_error(file, &(inst->labels_dec[inst->nb_labels_dec -
		                                           1].file_pose_col),
		                  &(inst->labels_dec[inst->nb_labels_dec -
		                                     1].file_pose_line),
		                  "error: label as not cmd and is not in the end");
		return 1;
	}
	else if (!inst->cmd.enum_token && !inst->next)
		return 0;
	while (i < OP_TAB_LENGTH)
	{
		//ft_printf("cmd: '%s', name '%s'\n", inst->cmd, gopt()[i].name);
		if (ft_strequ(gopt()[i].name, inst->cmd.data))
			return check_cmd(inst, gopt()[i]);
		i++;
	}
	/*
	print_local_error(file, &(inst->cmd),
	                  &(inst->labels_dec[inst->nb_labels_dec -
	                                     1].file_pose_line),
	                  "error: label as not cmd and is not in the end");
	*/
	ft_printf("error: un know cmd: %s\n", inst->cmd.data);
	return 1;
}

int check_insts(t_ast_inst *inst, char **file)
{
	//ft_printf("### check_insts\n");

	if (!inst)
		return 0;
	if (check_inst(inst, file))
		return 1;
	return check_insts(inst->next, file);
}
