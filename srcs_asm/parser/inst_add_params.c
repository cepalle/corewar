/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   inst_add_params.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/08 13:01:19 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/08 13:01:20 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

static void	print_and_set_error(t_ast_inst *ast_inst,
				t_lexer lexer_res, int *i, char *msg)
{
	print_local_error(lexer_res.file,
		&(lexer_res.tab_token.tokens[*i].file_pose_col),
		&(lexer_res.tab_token.tokens[*i].file_pose_line),
		msg);
	ast_inst->er = 1;
}

void		inst_add_params(t_ast_inst *a, t_lexer l, int *i)
{
	if (l.tab_token.tokens[*i].enum_token != TOKEN_DIRECT_LABEL &&
		l.tab_token.tokens[*i].enum_token != TOKEN_DIRECT_NUMBER &&
		l.tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_NUMBER &&
		l.tab_token.tokens[*i].enum_token != TOKEN_INDIRECT_LABEL &&
		l.tab_token.tokens[*i].enum_token != TOKEN_LABEL)
	{
		print_and_set_error(a, l, i, "parser: Need a param");
		return ;
	}
	if (a->nb_ast_params >= MAX_PARAMS)
	{
		print_and_set_error(a, l, i,
			"parser: command can't have more than 3 param");
		return ;
	}
	a->ast_params[a->nb_ast_params] = l.tab_token.tokens[*i];
	a->ast_params[a->nb_ast_params].data = ft_strdup(
			l.tab_token.tokens[*i].data);
	a->nb_ast_params++;
	(*i)++;
	if (l.tab_token.tokens[*i].enum_token == TOKEN_SEPARATOR_CHAR)
	{
		(*i)++;
		inst_add_params(a, l, i);
	}
}
