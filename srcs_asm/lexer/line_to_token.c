/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   line_to_token.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:39:06 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:39:07 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "op.h"
#include "libft.h"

static t_token	get_token_aux2(int *il, char **f, int *ic)
{
	t_token	token;

	ft_bzero(&token, sizeof(t_token));
	if (ft_isdigit(f[*il][*ic]) ||
			f[*il][*ic] == '-')
		return (get_indirect_number(il, f, ic));
	else if (f[*il][*ic] && ft_strchr(LABEL_CHARS, f[*il][*ic]))
		return (get_label(il, f, ic));
	else
	{
		print_local_error(f, ic, il, "lexer: Unexpected char");
		token.er = 1;
	}
	return (token);
}

static t_token	get_token_aux(int *il, char **f, int *ic)
{
	if (f[*il][*ic] == ',')
		return (get_separator_char(il, f, ic));
	else if (f[*il][*ic] == '.')
		return (get_dote_start(il, f, ic));
	else if (f[*il][*ic] == '%')
		return (get_direct(il, f, ic));
	else if (f[*il][*ic] == ':')
		return (get_indirect_label(il, f, ic));
	else if (f[*il][*ic] == '#' || f[*il][*ic] == ';')
		return (get_comment(il, f, ic));
	else if (f[*il][*ic] == '"')
		return (get_string(il, f, ic));
	return (get_token_aux2(il, f, ic));
}

t_token			get_token(int *i_line, char **file, int *i_col)
{
	t_token	token;
	int		i_line_sav;
	int		i_col_sav;

	i_line_sav = *i_line;
	i_col_sav = *i_col;
	ft_bzero(&token, sizeof(t_token));
	token = get_token_aux(i_line, file, i_col);
	while (file[*i_line] &&
		(file[*i_line][*i_col] == '\t' ||
		file[*i_line][*i_col] == ' '))
		(*i_col)++;
	token.file_pose_col = i_col_sav;
	token.file_pose_line = i_line_sav;
	return (token);
}

void			line_to_token(t_token *ltken, char **file, int *i_line)
{
	int		i_tken;
	int		i_col;

	i_tken = 0;
	i_col = 0;
	while (file[*i_line][i_col] == '\t' || file[*i_line][i_col] == ' ')
		i_col++;
	while (file[*i_line] && file[*i_line][i_col] && !ltken[0].er)
	{
		ltken[i_tken] = get_token(i_line, file, &i_col);
		if (i_tken + 2 >= LEN_LTOKEN)
		{
			print_local_error(NULL, NULL, i_line,
			"lexer: Too many token in one line");
			ltken[0].er = 1;
		}
		if (ltken[i_tken].er)
			ltken[0].er = 1;
		i_tken++;
	}
	ltken[i_tken].enum_token = TOKEN_EOL;
	ltken[i_tken].file_pose_line = *i_line;
	ltken[i_tken].file_pose_col = i_col;
}
