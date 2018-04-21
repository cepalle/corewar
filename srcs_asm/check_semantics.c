#include "asm.h"
#include "libft.h"
#include "op.h"

int is_registre(char *label)
{
	int reg_num;
	int er;

	er = 0;
	if (label[0] != 'r')
		return 0;
	label++;
	reg_num = ft_atoi_only(label, &er);
	if (er || reg_num <= 0 || reg_num > REG_NUMBER)
		return 0;
	return 1;
};

int check_registres(t_ast_inst *ast_inst)
{
	int i;

	if (!ast_inst)
		return 0;
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_LABEL &&
				!is_registre(ast_inst->ast_params[i].data))
		{
			ft_printf("no valid param registre '%s'\n", ast_inst->ast_params[i].data);
			return 1;
		}
		i++;
	}
	return check_registres(ast_inst->next);
};

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
};

int check_labels(t_parser parser_res, t_ast_inst *ast_inst)
{
	int i;

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
	return check_labels(parser_res, ast_inst->next);
};

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
	if (!inst)
		return 0;
	if (check_inst(inst))
		return 1;
	return check_insts(inst->next);
};

int check_ast(t_parser parser_res)
{
	if (!ft_strlen(parser_res.ast_prog.prog_name) ||
			ft_strlen(parser_res.ast_prog.prog_name) > PROG_NAME_LENGTH ||
			ft_strlen(parser_res.ast_prog.prog_comment) > COMMENT_LENGTH ||
			check_registres(parser_res.ast_prog.ast_inst) ||
			check_labels(parser_res, parser_res.ast_prog.ast_inst) ||
			check_insts(parser_res.ast_prog.ast_inst))
	{
		// free parser_res
		return 1;
	}
	return 0;
};
