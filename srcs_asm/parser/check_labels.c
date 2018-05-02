/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_labels.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:40:41 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:40:43 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

int		check_label_if_exist(t_ast_inst *ast_inst, const char *to_find)
{
	int	i;

	if (!ast_inst)
		return (1);
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (ft_strequ(to_find, ast_inst->labels_dec[i].data))
			return (0);
		i++;
	}
	return (check_label_if_exist(ast_inst->next, to_find));
}

int		check_labels_params(t_parser parser_res,
							t_ast_inst *ast_inst, char **file)
{
	int		i;

	if (!ast_inst)
		return (0);
	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if ((ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL ||
			ast_inst->ast_params[i].enum_token == TOKEN_INDIRECT_LABEL) &&
			check_label_if_exist(parser_res.ast_prog.ast_inst,
								ast_inst->ast_params[i].data))
		{
			print_local_error(file, &(ast_inst->ast_params[i].file_pose_col),
							&(ast_inst->ast_params[i].file_pose_line),
							"label is not declare");
			return (1);
		}
		i++;
	}
	return (check_labels(parser_res, ast_inst->next, file));
}

int		check_inst_label_dec(t_ast_inst *ast_inst, char **file)
{
	int		i;
	int		j;

	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		j = i + 1;
		while (j < ast_inst->nb_labels_dec)
		{
			if (ft_strequ(ast_inst->labels_dec[i].data,
						ast_inst->labels_dec[j].data))
			{
				print_local_error(file,
								&(ast_inst->labels_dec[j].file_pose_col),
								&(ast_inst->labels_dec[j].file_pose_line),
								"label already declared");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int		check_labels_dec(t_parser parser_res, t_ast_inst *ast_inst, char **file)
{
	int	i;

	if (!ast_inst)
		return (0);
	if (check_inst_label_dec(ast_inst, file))
		return (1);
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		if (!check_label_if_exist(ast_inst->next, ast_inst->labels_dec[i].data))
		{
			print_local_error(file, &(ast_inst->labels_dec[i].file_pose_col),
							&(ast_inst->labels_dec[i].file_pose_line),
							"label is declared more than on times");
			return (1);
		}
		i++;
	}
	return (check_labels_dec(parser_res, ast_inst->next, file));
}

int		check_labels(t_parser parser_res, t_ast_inst *ast_inst, char **file)
{
	return (check_labels_dec(parser_res, ast_inst, file) ||
			check_labels_params(parser_res, ast_inst, file));
}
