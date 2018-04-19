#include "asm.h"
#include "libft.h"


void print_tab_token(t_tab_token tab_token)
{
	int i;

	i = 0;
	if (tab_token.i < 0)
		return;
	while (i <= tab_token.i)
	{
		if (tab_token.tokens[i].enum_token == TOKEN_PROG_NAME)
			ft_printf(".name ");
		if (tab_token.tokens[i].enum_token == TOKEN_PROG_COMMENT)
			ft_printf(".comment ");
		if (tab_token.tokens[i].enum_token == TOKEN_LABEL)
			ft_printf("%s ", tab_token.tokens[i].data);
		if (tab_token.tokens[i].enum_token == TOKEN_NUMBER)
			ft_printf("%s ", tab_token.tokens[i].data);
		if (tab_token.tokens[i].enum_token == TOKEN_STRING)
			ft_printf("'%s' ", tab_token.tokens[i].data);
		if (tab_token.tokens[i].enum_token == TOKEN_COMMENT)
			ft_printf("#%s", tab_token.tokens[i].data);
		if (tab_token.tokens[i].enum_token == TOKEN_LABEL_CHAR)
			ft_printf(":");
		if (tab_token.tokens[i].enum_token == TOKEN_MINUS)
			ft_printf("-");
		if (tab_token.tokens[i].enum_token == TOKEN_PLUS)
			ft_printf("+");
		if (tab_token.tokens[i].enum_token == TOKEN_DIRECT_CHAR)
			ft_printf("%%");
		if (tab_token.tokens[i].enum_token == TOKEN_SEPARATOR_CHAR)
			ft_printf(", ");
		if (tab_token.tokens[i].enum_token == TOKEN_EOL)
			ft_printf("\n");
		i++;
	};
};

void init_tab_token(t_tab_token *tab_token)
{
	tab_token->len = TAB_TOKEN_LEN_INIT;
	tab_token->i = -1;
	tab_token->tokens = ft_memalloc(sizeof(t_token) * tab_token->len);
};

void tab_token_add(t_tab_token *tab_token, t_token tken) {
	if (!tab_token->tokens)
		init_tab_token(tab_token);

	tab_token->i++;
	if (tab_token->i >= tab_token->len)
	{
		tab_token->tokens = ft_realloc(tab_token->tokens, sizeof(t_token) * tab_token->len, sizeof(t_token) * tab_token->len * 2);
		tab_token->len = tab_token->len * 2;
	}
	tab_token->tokens[tab_token->i] = tken;
};

void tab_token_multi_add(t_tab_token *tab_token, t_token *ltken)
{
	int i;

	if (!tab_token->tokens)
		init_tab_token(tab_token);
	i = 0;
	while (1)
	{
		tab_token_add(tab_token, ltken[i]);
		if (ltken[i].enum_token == TOKEN_EOL)
            break;
		i++;
	}
};
