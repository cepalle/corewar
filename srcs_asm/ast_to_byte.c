#include "asm.h"
#include "libft.h"


void ast_to_byte(t_parser parser_res, char *file_name)
{
	int fd;

	ft_printf("open_new_file\n");
	fd = open_new_file(file_name);
	if (fd < 0)
		return;
	ft_printf("inst_feed_label_dec\n");
	inst_feed_label_dec(parser_res.ast_prog.ast_inst, 0);
	ft_printf("insts_feed_label\n");
	insts_feed_label(parser_res, parser_res.ast_prog.ast_inst);
	ft_printf("write_header\n");
	write_header(fd, parser_res);
	ft_printf("write_insts\n");
	write_insts(fd, parser_res.ast_prog.ast_inst, 0);
	ft_printf("end\n");
};
