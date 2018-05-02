/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ast_to_byte.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 12:56:17 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 12:56:51 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"

void	ast_to_byte(t_parser parser_res, char *file_name)
{
	int	fd;

	fd = open_new_file(file_name);
	if (fd < 0)
		return ;
	inst_feed_label_dec(parser_res.ast_prog.ast_inst, 0);
	insts_feed_label(parser_res, parser_res.ast_prog.ast_inst);
	write_header(fd, parser_res);
	write_insts(fd, parser_res.ast_prog.ast_inst, 0);
}
