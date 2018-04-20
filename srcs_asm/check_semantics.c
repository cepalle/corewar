#include "asm.h"
#include "libft.h"
#include "op.h"

int check_live(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_ld(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_st(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_add(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_sub(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_and(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_or(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_xor(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_zjmp(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_ldi(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_sti(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_fork(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_lld(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_lldi(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_lfork(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_aff(t_parser parser_res, t_ast_inst *inst)
{
	(void)parser_res;
	(void)inst;
	return 0;
};

int check_inst(t_parser parser_res, t_ast_inst *inst)
{
	if (ft_strequ(inst->cmd, "live"))
		return check_live(parser_res, inst);
	if (ft_strequ(inst->cmd, "ld"))
		return check_ld(parser_res, inst);
	if (ft_strequ(inst->cmd, "st"))
		return check_st(parser_res, inst);
	if (ft_strequ(inst->cmd, "add"))
		return check_add(parser_res, inst);
	if (ft_strequ(inst->cmd, "sub"))
		return check_sub(parser_res, inst);
	if (ft_strequ(inst->cmd, "and"))
		return check_and(parser_res, inst);
	if (ft_strequ(inst->cmd, "or"))
		return check_or(parser_res, inst);
	if (ft_strequ(inst->cmd, "xor"))
		return check_xor(parser_res, inst);
	if (ft_strequ(inst->cmd, "zjmp"))
		return check_zjmp(parser_res, inst);
	if (ft_strequ(inst->cmd, "ldi"))
		return check_ldi(parser_res, inst);
	if (ft_strequ(inst->cmd, "sti"))
		return check_sti(parser_res, inst);
	if (ft_strequ(inst->cmd, "fork"))
		return check_fork(parser_res, inst);
	if (ft_strequ(inst->cmd, "lld"))
		return check_lld(parser_res, inst);
	if (ft_strequ(inst->cmd, "lldi"))
		return check_lldi(parser_res, inst);
	if (ft_strequ(inst->cmd, "lfork"))
		return check_lfork(parser_res, inst);
	if (ft_strequ(inst->cmd, "aff"))
		return check_aff(parser_res, inst);
	else
	{
		ft_printf("semantics error: unknow cmd: %s", inst->cmd);
		return 1;
	}
};

int check_insts(t_parser parser_res, t_ast_inst *inst)
{
	if (!inst)
		return 0;
	if (check_inst(parser_res, inst))
		return 1;
	return check_insts(parser_res, inst->next);
};

int check_semantics(t_parser parser_res)
{
	if (!ft_strlen(parser_res.ast_prog.prog_name) ||
					ft_strlen(parser_res.ast_prog.prog_name) > PROG_NAME_LENGTH ||
					check_insts(parser_res, parser_res.ast_prog.ast_inst))
	{
		// free
		return 1;
	}
	return 0;
};
