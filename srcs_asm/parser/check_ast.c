/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_ast.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:40:26 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:40:28 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"

int		check_ast(t_parser parser_res, char **file)
{
	if (!parser_res.ast_prog.prog_name ||
			!ft_strlen(parser_res.ast_prog.prog_name))
		return (ft_printf("error: The program must have a name\n"));
	else if (ft_strlen(parser_res.ast_prog.prog_name) > PROG_NAME_LENGTH)
		return (ft_printf(
			"error: Program name can't be contain more than 128 char\n"));
	else if (parser_res.ast_prog.prog_comment &&
			ft_strlen(parser_res.ast_prog.prog_comment) > COMMENT_LENGTH)
		return (ft_printf(
			"error: Program comment can't be contain more than 2048 char\n"));
	else if (!prog_len(parser_res.ast_prog.ast_inst))
		return (ft_printf("error: The program is empty\n"));
	else if (check_registres(parser_res.ast_prog.ast_inst, file) ||
			check_labels(parser_res, parser_res.ast_prog.ast_inst, file) ||
			check_insts(parser_res.ast_prog.ast_inst, file))
		return (1);
	return (0);
}
