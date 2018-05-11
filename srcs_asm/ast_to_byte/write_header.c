/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_header.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 13:21:35 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 13:21:41 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "libft.h"
#include <unistd.h>

void	write_header(int fd, t_parser parser_res)
{
	t_header header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	swap_4(&(header.magic));
	ft_strcpy(header.prog_name, parser_res.ast_prog.prog_name);
	header.prog_size = prog_len(parser_res.ast_prog.ast_inst);
	swap_4(&(header.prog_size));
	if (parser_res.ast_prog.prog_comment)
		ft_strcpy(header.comment, parser_res.ast_prog.prog_comment);
	if (write(fd, &header, sizeof(t_header)) != sizeof(t_header))
	{
		ft_printf("Unexpected error, can't write the file.cor\n");
		free_parser(parser_res);
		exit(1);
	}
}
