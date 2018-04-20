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

int check_live(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 1 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER))
	{
		ft_printf("live bad parameters\n");
		return 1;
	}
	return 0;
};

int check_ld(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 2 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[0].enum_token != TOKEN_INDIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_INDIRECT_NUMBER) ||
			inst->ast_params[1].enum_token != TOKEN_LABEL)
	{
		ft_printf("ld bad parameters\n");
		return 1;
	}
	return 0;
};

int check_st(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 2 ||
			inst->ast_params[0].enum_token != TOKEN_LABEL ||
			(inst->ast_params[1].enum_token != TOKEN_LABEL &&
			 inst->ast_params[1].enum_token != TOKEN_INDIRECT_LABEL &&
			 inst->ast_params[1].enum_token != TOKEN_INDIRECT_NUMBER))
	{
		ft_printf("st bad parameters\n");
		return 1;
	}
	return 0;
};

int check_add(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[0].enum_token != TOKEN_LABEL ||
			inst->ast_params[1].enum_token != TOKEN_LABEL ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("add bad parameters\n");
		return 1;
	}
	return 0;
};

int check_sub(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[0].enum_token != TOKEN_LABEL ||
			inst->ast_params[1].enum_token != TOKEN_LABEL ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("sub bad parameters\n");
		return 1;
	}
	return 0;
};

int check_and(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("and bad parameters\n");
		return 1;
	}
	return 0;
};

int check_or(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("or bad parameters\n");
		return 1;
	}
	return 0;
};

int check_xor(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("xor bad parameters\n");
		return 1;
	}
	return 0;
};

int check_zjmp(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 1 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL))
	{
		ft_printf("zjmp bad parameters\n");
		return 1;
	}
	return 0;
};

int check_ldi(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			(inst->ast_params[1].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[1].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[1].enum_token != TOKEN_LABEL) ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("ldi bad parameters\n");
		return 1;
	}
	return 0;
};

int check_sti(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			inst->ast_params[0].enum_token != TOKEN_LABEL ||
			(inst->ast_params[2].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[2].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[2].enum_token != TOKEN_LABEL))
	{
		ft_printf("sti bad parameters\n");
		return 1;
	}
	return 0;
};

int check_fork(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 1 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL))
	{
		ft_printf("fork bad parameters\n");
		return 1;
	}
	return 0;
};

int check_lld(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 2 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_INDIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_INDIRECT_NUMBER) ||
			inst->ast_params[1].enum_token != TOKEN_LABEL)
	{
		ft_printf("lld bad parameters\n");
		return 1;
	}
	return 0;
};

int check_lldi(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 3 ||
			(inst->ast_params[1].enum_token != TOKEN_LABEL &&
			 inst->ast_params[1].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[1].enum_token != TOKEN_DIRECT_NUMBER) ||
			inst->ast_params[2].enum_token != TOKEN_LABEL)
	{
		ft_printf("lldi bad parameters\n");
		return 1;
	}
	return 0;
};

int check_lfork(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 1 ||
			(inst->ast_params[0].enum_token != TOKEN_DIRECT_LABEL &&
			 inst->ast_params[0].enum_token != TOKEN_DIRECT_NUMBER))
	{
		ft_printf("lfork bad parameters\n");
		return 1;
	}
	return 0;
};

int check_aff(t_ast_inst *inst)
{
	if (inst->nb_ast_params != 1 ||
			inst->ast_params[0].enum_token != TOKEN_LABEL)
	{
		ft_printf("aff bad parameters\n");
		return 1;
	}
	return 0;
};

int check_inst(t_ast_inst *inst)
{
	if (ft_strequ(inst->cmd, "live"))
		return check_live(inst);
	if (ft_strequ(inst->cmd, "ld"))
		return check_ld(inst);
	if (ft_strequ(inst->cmd, "st"))
		return check_st(inst);
	if (ft_strequ(inst->cmd, "add"))
		return check_add(inst);
	if (ft_strequ(inst->cmd, "sub"))
		return check_sub(inst);
	if (ft_strequ(inst->cmd, "and"))
		return check_and(inst);
	if (ft_strequ(inst->cmd, "or"))
		return check_or(inst);
	if (ft_strequ(inst->cmd, "xor"))
		return check_xor(inst);
	if (ft_strequ(inst->cmd, "zjmp"))
		return check_zjmp(inst);
	if (ft_strequ(inst->cmd, "ldi"))
		return check_ldi(inst);
	if (ft_strequ(inst->cmd, "sti"))
		return check_sti(inst);
	if (ft_strequ(inst->cmd, "fork"))
		return check_fork(inst);
	if (ft_strequ(inst->cmd, "lld"))
		return check_lld(inst);
	if (ft_strequ(inst->cmd, "lldi"))
		return check_lldi(inst);
	if (ft_strequ(inst->cmd, "lfork"))
		return check_lfork(inst);
	if (ft_strequ(inst->cmd, "aff"))
		return check_aff(inst);
	else
	{
		ft_printf("error: unknow cmd: %s", inst->cmd);
		return 1;
	}
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
