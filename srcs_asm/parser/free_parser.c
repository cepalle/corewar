/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   free_parser.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:41:01 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:41:02 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

void	free_ast_inst(t_ast_inst *ast_inst)
{
	int		i;

	i = 0;
	if (!ast_inst)
		return ;
	free_ast_inst(ast_inst->next);
	while (i < ast_inst->nb_labels_dec)
	{
		ft_memdel((void **)&(ast_inst->labels_dec[i].data));
		i++;
	}
	ft_memdel((void **)&(ast_inst->cmd.data));
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		ft_memdel((void **)&(ast_inst->ast_params[i].data));
		i++;
	}
	ft_memdel((void **)&ast_inst);
}

void	free_parser(t_parser parser_res)
{
	ft_memdel((void **)&(parser_res.ast_prog.prog_comment));
	ft_memdel((void **)&(parser_res.ast_prog.prog_name));
	free_ast_inst(parser_res.ast_prog.ast_inst);
}
