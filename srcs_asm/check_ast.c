#include "asm.h"
#include "libft.h"
#include "op.h"

int check_ast(t_parser parser_res)
{
	ft_printf("### check_ast\n");

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
