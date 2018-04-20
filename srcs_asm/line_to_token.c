#include "asm.h"
#include "op.h"
#include <stdlib.h>
#include "libft.h"

t_token get_dote_start_token(int *i_line, const char *line, int line_file)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));

	if (ft_strnequ(".name", line + *i_line, 5))
	{
		token.enum_token = TOKEN_PROG_NAME;
		*i_line = *i_line + 5;
		return token;
	}
	if (ft_strnequ(".comment", line + *i_line, 8))
	{
		token.enum_token = TOKEN_PROG_COMMENT;
		*i_line = *i_line + 8;
		return token;
	}
	ft_printf("lexer error: line %d: get_dote_start_token, Unexpected token after '.'\n", line_file);
	token.er = 1;
	return (token);
};

t_token get_indirect_number(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_NUMBER;
	token.data = ft_strdup(line + *i_line);

	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	if (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_indirect_number, Unexpected token\n", line_file);
	}
	token.data[i] = '\0';
	if (i == 1 && token.data[i] == '-')
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_indirect_number, no number found after '-'\n", line_file);
	}
	*i_line = *i_line + i;
	return (token);
};

t_token get_label(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	(void)line_file;
	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_LABEL;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (line[*i_line + i] == ':')
	{
		token.enum_token = TOKEN_LABEL_DECLARATION;
		(*i_line)++;
	}
	*i_line = *i_line + i;
	return (token);
};

t_token get_separator_char(int *i_line, const char *line, int line_file)
{
	t_token token;

	(void)line_file;
	(void)line;
	ft_bzero(&token, sizeof(t_token));

	token.enum_token = TOKEN_SEPARATOR_CHAR;

	(*i_line)++;
	return (token);
};

t_token get_comment(int *i_line, const char *line, int line_file)
{
	t_token token;

	(void)line_file;
	ft_bzero(&token, sizeof(t_token));
	(*i_line)++;
	token.enum_token = TOKEN_COMMENT;
	token.data = ft_strdup(line + *i_line);
	*i_line = *i_line + (int)ft_strlen(token.data);
	return (token);
};

t_token get_string(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_STRING;
	(*i_line)++;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i])
	{
		if (token.data[i] == '"')
		{
			token.data[i] = '\0';
			*i_line = *i_line + i + 1;
			return token;
		}
		i++;
	}
	free(token.data);
	token.er = 1;
	ft_printf("lexer error: line %d: get_string, Unclosed string in the same line\n", line_file);
	return (token);
};

t_token get_indirect_label(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_INDIRECT_LABEL;
	(*i_line)++;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (!ft_strlen(token.data))
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_indirect_label expected label after ':'\n", line_file);
	}
	*i_line = *i_line + i;
	return (token);
};

t_token get_direct_label(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_DIRECT_LABEL;
	(*i_line)++;
	token.data = ft_strdup(line + *i_line);

	while (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
		i++;
	token.data[i] = '\0';
	if (!ft_strlen(token.data))
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_direct_label expected label after ':'\n", line_file);
	}
	*i_line = *i_line + i;
	return (token);
};

t_token get_direct_number(int *i_line, const char *line, int line_file)
{
	t_token token;
	int i;

	ft_bzero(&token, sizeof(t_token));
	i = 0;
	token.enum_token = TOKEN_DIRECT_NUMBER;
	token.data = ft_strdup(line + *i_line);

	if (token.data[i] == '-')
		i++;
	while (ft_isdigit(token.data[i]))
		i++;
	if (token.data[i] && ft_strchr(LABEL_CHARS, token.data[i]))
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_direct_number, Unexpected token\n", line_file);
	}
	if (i == 1 && token.data[i] == '-')
	{
		free(token.data);
		token.er = 1;
		ft_printf("lexer error: line %d: get_direct_number, no number found after '-'\n", line_file);
	}

	token.data[i] = '\0';
	*i_line = *i_line + i;
	return (token);
};

t_token get_direct(int *i_line, const char *line, int line_file)
{
	t_token token;

	(*i_line)++;

	ft_bzero(&token, sizeof(t_token));
	if (line[*i_line] == ':')
		token = get_direct_label(i_line, line, line_file);
	else if (ft_isdigit(line[*i_line]) || line[*i_line] == '-')
		token = get_direct_number(i_line, line, line_file);
	else
	{
		token.er = 1;
		ft_printf("lexer error: line %d: get_direct excepted ':' or digit\n", line_file);
	}
	return token;
};

t_token get_token(int *i_line, const char *line, int line_file)
{
	t_token token;

	ft_bzero(&token, sizeof(t_token));

	if (line[*i_line] == ',')
		token = get_separator_char(i_line, line, line_file);
	else if (line[*i_line] == '.')
		token = get_dote_start_token(i_line, line, line_file);
	else if (line[*i_line] == '%')
		token = get_direct(i_line, line, line_file);
	else if (line[*i_line] == ':')
		token = get_indirect_label(i_line, line, line_file);
	else if (line[*i_line] == '#' || line[*i_line] == ';')
		token = get_comment(i_line, line, line_file);
	else if (line[*i_line] == '"')
		token = get_string(i_line, line, line_file);
	else if (ft_isdigit(line[*i_line]) || line[*i_line] == '-')
		token = get_indirect_number(i_line, line, line_file);
	else if (line[*i_line] && ft_strchr(LABEL_CHARS, line[*i_line]))
		token = get_label(i_line, line, line_file);
	else
	{
		ft_printf("lexer error: line %d: get_token, Unexpected char: '%c' %d\n", line_file, line[*i_line], line[*i_line] == '\t');
		token.er = 1;
	};
	while (line[*i_line] == '\t' || line[*i_line] == ' ')
		(*i_line)++;
	return token;
}

void line_to_token(t_token *ltken, char *line, int line_file)
{
	int i_tken;
	int i_line;

	i_tken = 0;
	i_line = 0;

	while (line[i_line] == '\t' || line[i_line] == ' ')
		i_line++;
	while (line[i_line] && !ltken[0].er)
	{
		ltken[i_tken] = get_token(&i_line, line, line_file);
		if (i_tken >= LEN_LTOKEN)
		{
			ft_printf("lexer error: line %d:line_to_token, Too many token in one line\n", line_file);
			ltken[0].er = 1;
		}
		if (ltken[i_tken].er)
			ltken[0].er = 1;
		i_tken++;
	}
	ltken[i_tken].enum_token = TOKEN_EOL;
};
