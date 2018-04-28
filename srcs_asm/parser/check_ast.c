#include "asm.h"
#include "libft.h"
#include "op.h"

int check_ast(t_parser parser_res, char **file)
{
	int er;

	er = 0;

	if(!ft_strlen(parser_res.ast_prog.prog_name))
	{
		ft_printf("error: Program name can't be empty\n");
		er = 1;
	}
	else if (ft_strlen(parser_res.ast_prog.prog_name) > PROG_NAME_LENGTH)
	{
		ft_printf("error: Program name can't be contain more than 128 char\n");
		er = 1;
	}
	else if (ft_strlen(parser_res.ast_prog.prog_comment) > COMMENT_LENGTH)
	{
		ft_printf("error: Program comment can't be contain more than 2048 char\n");
		er = 1;
	}
	else if (!prog_len(parser_res.ast_prog.ast_inst))
	{
		ft_printf("error: The program is empty\n");
		er = 1;
	}
	else if (check_registres(parser_res.ast_prog.ast_inst, file) ||
	    check_labels(parser_res, parser_res.ast_prog.ast_inst, file) ||
	    check_insts(parser_res.ast_prog.ast_inst, file))
		er = 1;
	return (er);
}
