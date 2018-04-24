#include "libft.h"
#include "asm.h"
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

	ft_printf("## check_registres\n");

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

