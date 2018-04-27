#include "asm.h"
#include "op.h"
#include "libft.h"
#include <unistd.h>

void write_header(int fd, t_parser parser_res)
{
	t_header header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	swap_4(&(header.magic));
	ft_strcpy(header.prog_name, parser_res.ast_prog.prog_name);
	header.prog_size = prog_len(parser_res.ast_prog.ast_inst);
	swap_4(&(header.prog_size));
	ft_strcpy(header.comment, parser_res.ast_prog.prog_comment);

	write(fd, &header, sizeof(t_header));
}

