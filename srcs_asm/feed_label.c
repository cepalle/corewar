#include "asm.h"
#include "op.h"
#include "libft.h"

void inst_feed_label_dec(t_ast_inst *ast_inst, int pos)
{
	int i;

	if (!ast_inst)
		return;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		ast_inst->labels_dec[i].pos_octet_label_dec = pos;
		i++;
	}
	inst_feed_label_dec(ast_inst->next, pos + inst_len(ast_inst));
};

int find_label_pos(t_ast_inst *ast_inst, char *label)
{
	int i;

	if (!ast_inst)
	{
		ft_printf("find_label_pos, label not found\n");
		return 0;
	}
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ft_strequ(ast_inst->labels_dec[i].data, label))
			return ast_inst->labels_dec[i].pos_octet_label_dec;
		i++;
	}
	return find_label_pos(ast_inst->next, label);
}

void token_label_feed_pos(t_parser parser_res, t_token *token)
{
	token->pos_octet_label_dec = find_label_pos(parser_res.ast_prog.ast_inst,
	                                            token->data);
};

void inst_feed_label(t_parser parser_res, t_ast_inst *ast_inst)
{
	int i;

	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_INDIRECT_LABEL ||
		    ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL)
			token_label_feed_pos(parser_res, ast_inst->ast_params + i);
		i++;
	}
};

void insts_feed_label(t_parser parser_res, t_ast_inst *ast_inst)
{
	if (!ast_inst)
		return;

	inst_feed_label(parser_res, ast_inst->next);
	insts_feed_label(parser_res, ast_inst->next);
};
