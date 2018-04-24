#include "asm.h"
#include "libft.h"


void ast_to_byte(t_parser parser_res, char *file_name)
{
	int fd;

	ft_printf("0\n");
	fd = open_new_file(file_name);
	if (fd < 0)
		return;
	ft_printf("1\n");
	inst_feed_label_dec(parser_res.ast_prog.ast_inst, 0);
	ft_printf("2\n");
	insts_feed_label(parser_res, parser_res.ast_prog.ast_inst);
	ft_printf("3\n");
	write_header(fd, parser_res);
	ft_printf("4\n");
	write_insts(fd, parser_res.ast_prog.ast_inst, 0);
	ft_printf("5\n");
};
