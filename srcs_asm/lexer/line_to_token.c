#include "asm.h"
#include "op.h"
#include "libft.h"

t_token get_token(int *i_line, char **file, int *i_col)
{
	t_token token;
	int i_line_sav;
	int i_col_sav;

	i_line_sav = *i_line;
	i_col_sav = *i_col;
	ft_bzero(&token, sizeof(t_token));
	if (file[*i_line][*i_col] == ',')
		token = get_separator_char(i_line, file, i_col);
	else if (file[*i_line][*i_col] == '.')
		token = get_dote_start(i_line, file, i_col);
	else if (file[*i_line][*i_col] == '%')
		token = get_direct(i_line, file, i_col);
	else if (file[*i_line][*i_col] == ':')
		token = get_indirect_label(i_line, file, i_col);
	else if (file[*i_line][*i_col] == '#' || file[*i_line][*i_col] == ';')
		token = get_comment(i_line, file, i_col);
	else if (file[*i_line][*i_col] == '"')
		token = get_string(i_line, file, i_col);
	else if (ft_isdigit(file[*i_line][*i_col]) ||
	         file[*i_line][*i_col] == '-')
		token = get_indirect_number(i_line, file, i_col);
	else if (file[*i_line][*i_col] &&
	         ft_strchr(LABEL_CHARS, file[*i_line][*i_col]))
		token = get_label(i_line, file, i_col);
	else
	{
		print_local_error(file, i_col, i_line,
		                  "lexer: Unexpected char");
		token.er = 1;
	};
	while (file[*i_line] &&
	       (file[*i_line][*i_col] == '\t' ||
	        file[*i_line][*i_col] == ' '))
		(*i_col)++;
	token.file_pose_col = i_col_sav;
	token.file_pose_line = i_line_sav;
	return token;
}

void line_to_token(t_token *ltken, char **file, int *i_line)
{
	int i_tken;
	int i_col;

	i_tken = 0;
	i_col = 0;

	while (file[*i_line][i_col] == '\t' || file[*i_line][i_col] == ' ')
		i_col++;
	while (file[*i_line][i_col] && !ltken[0].er)
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
}
