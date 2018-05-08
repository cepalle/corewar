/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ast_dote_start.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:40:16 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:40:17 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"

static void	print_and_set_error(t_parser *parser_res, t_lexer *lexer_res,
								int *i, char *msg)
{
	print_local_error(lexer_res->file,
					&(lexer_res->tab_token.tokens[*i].file_pose_col),
					&(lexer_res->tab_token.tokens[*i].file_pose_line),
					msg);
	parser_res->er = 1;
}

void		ast_add_dote_start(t_parser *parser_res, t_lexer lexer_res, int *i)
{
	char	*error_msg;

	error_msg = NULL;
	if (*i + 1 > lexer_res.tab_token.i)
		error_msg = "parser: Dote start, not String found";
	else if (lexer_res.tab_token.tokens[*i + 1].enum_token != TOKEN_STRING)
		error_msg = "parser: Dote start, not String found";
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_NAME &&
			parser_res->ast_prog.prog_name)
		error_msg = "parser: Dote start, you can use only one '.name'";
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT &&
			parser_res->ast_prog.prog_comment)
		error_msg = "parser: Dote start, you can use only one '.comment'";
	if (error_msg)
		print_and_set_error(parser_res, &lexer_res, i, error_msg);
	else if (lexer_res.tab_token.tokens[*i].enum_token == TOKEN_PROG_COMMENT)
		parser_res->ast_prog.prog_comment = ft_strdup(
				lexer_res.tab_token.tokens[*i + 1].data);
	else
		parser_res->ast_prog.prog_name = ft_strdup(
				lexer_res.tab_token.tokens[*i + 1].data);
	*i = *i + 3;
}
