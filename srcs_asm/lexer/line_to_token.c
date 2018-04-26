#include "asm.h"
#include "op.h"
#include "libft.h"

t_token get_token(int *i_line, char **files, int *i_files)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));
	token.file_pose_col = *i_line;
	token.file_pose_line = *i_files;
	if (files[*i_files][*i_line] == ',')
		token = get_separator_char(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] == '.')
		token = get_dote_start(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] == '%')
		token = get_direct(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] == ':')
		token = get_indirect_label(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] == '#' || files[*i_files][*i_line] == ';')
		token = get_comment(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] == '"')
		token = get_string(i_line, files, i_files);
	else if (ft_isdigit(files[*i_files][*i_line]) ||
	         files[*i_files][*i_line] == '-')
		token = get_indirect_number(i_line, files[*i_files], *i_files);
	else if (files[*i_files][*i_line] &&
	         ft_strchr(LABEL_CHARS, files[*i_files][*i_line]))
		token = get_label(i_line, files[*i_files], *i_files);
	else
	{
		ft_printf(
				"lexer error: line %d column %d get_token, Unexpected char: '%c'\n",
				*i_files, *i_line, files[*i_files][*i_line]);
		token.er = 1;
	};
	while (files[*i_files] &&
	       (files[*i_files][*i_line] == '\t' ||
	        files[*i_files][*i_line] == ' '))
		(*i_line)++;
	return token;
}

void line_to_token(t_token *ltken, char **files, int *i_files)
{
	int i_tken;
	int i_line;

	i_tken = 0;
	i_line = 0;

	while (files[*i_files][i_line] == '\t' || files[*i_files][i_line] == ' ')
		i_line++;
	while (files[*i_files][i_line] && !ltken[0].er)
	{
		ltken[i_tken] = get_token(&i_line, files, i_files);
		if (i_tken + 2 >= LEN_LTOKEN)
		{
			print_local_error(NULL, NULL, i_files,
			                  "lexer: Too many token in one line");
			ltken[0].er = 1;
		}
		if (ltken[i_tken].er)
			ltken[0].er = 1;
		i_tken++;
	}
	ltken[i_tken].enum_token = TOKEN_EOL;
}
