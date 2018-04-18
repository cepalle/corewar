#include "asm.h"
#include "op.h"
#include <stdlib.h>
#include "libft.h"

t_token get_dote_start_token(int *i_token, const char *line, int line_file)
{
	t_token token;

	token = {0, 0, NULL};




	return (token);
};

t_token get_digit(int *i_token, const char *line, int line_file)
{
	t_token token;

	token = {0, 0, NULL};




	return (token);
};

t_token get_label(int *i_token, const char *line, int line_file)
{
	t_token token;

	token = {0, 0, NULL};




	return (token);
};

t_token get_single_char_token(int *i_token, const char *line, int line_file)
{
	t_token token;

	(void)line_file;
	token = {0, 0, NULL};

	if (line[*i_token] == ':')
		token.enum_token = TOKEN_LABEL_CHAR;
	else if (line[*i_token] == '-')
		token.enum_token = TOKEN_MINUS;
	else if (line[*i_token] == '+')
		token.enum_token = TOKEN_PLUS;
	else if (line[*i_token] == '%')
		token.enum_token = TOKEN_DIRECT_CHAR;
	else
		token.enum_token = TOKEN_SEPARATOR_CHAR;

	(*i_token)++;
	return (token);
};

t_token get_comment(int *i_token, const char *line, int line_file)
{
	t_token token;

	(void)line_file;
	token = {0, 0, NULL};
	(*i_token)++;
	token.enum_token = TOKEN_COMMENT;
	token.data = ft_strdup(line + *i_token);
	return (token);
};

t_token get_string(int *i_token, const char *line, int line_file)
{
	t_token token;
	int i;

	token = {0, 0, NULL};
	i = 0;
	(*i_token)++;
	token.enum_token = TOKEN_STRING;
	token.data = ft_strdup(line + *i_token);

	while (token.data[i])
	{
		if (token.data[i] == '"')
		{
			token.data[i] = '\0';
			return token;
		}
		i++;
	}
	free(token.data);
	token.er = 1;
	ft_printf("line %d: Unclosed string\n", line_file);
	return (token);
};

t_token get_token(int *i_token, const char *line, int line_file)
{
	t_token token;

	token = {0, 0, NULL};

	if (ft_strchr(":-+%,", line[*i_token]))
		token = get_single_char_token(i_token, line, line_file);
	else if (line[*i_token] == '.')
		token = get_dote_start_token(i_token, line, line_file);
	else if (line[*i_token] == '#')
		token = get_comment(i_token, line, line_file);
	else if (line[*i_token] == '"')
		token = get_string(i_token, line, line_file);
	else if (ft_isdigit(line[*i_token]))
		token = get_digit(i_token, line, line_file);
	else if (ft_strchr(LABEL_CHARS, line[*i_token]))
		token = get_label(i_token, line, line_file);
	else
	{
		ft_printf("line %d: Unexpected token: %c\n", line_file, line[*i_token]);
		token.er = 1;
	};
	while (line[*i_token] == '\t' || line[*i_token] == ' ')
		(*i_token)++;
	return token;
}

void line_to_token(t_token *ltken, char *line)
{
	int i_tken;
	int i_line;
	int line_file;

	i_tken = 0;
	i_line = 0;
	line_file = 0;

	while (line[i_tken] == '\t' || line[i_tken] == ' ')
		i_tken++;
	while (line[i_line] && !ltken[0].er)
	{
		ltken[i_tken] = get_token(&i_line, line + i_line, line_file);
		if (i_tken > 15)
		{
			ft_printf("line %d: Too many token in one line\n", line_file);
			ltken[0].er = 1;
		}
		if (ltken[i_tken].er)
			ltken[0].er = 1;
		i_tken++;
	}
	ltken[i_tken].enum_token = TOKEN_EOL;
};
