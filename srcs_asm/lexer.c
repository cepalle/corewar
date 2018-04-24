#include "../includes/asm.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>


t_lexer lexer(t_cmdl cmdl)
{
    t_lexer lexer_res;
    t_token ltken[LEN_LTOKEN];
    char *line;
    int line_num;

    ft_bzero(&lexer_res, sizeof(t_lexer));
    ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
    line_num = 1;
    while (get_next_line(cmdl.fd, &line) > 0)
    {
        line_to_token(ltken, &line, &line_num, cmdl.fd);
        free(line);
        if (ltken[0].er)
        {
            //free
            lexer_res.er = 1;
            return lexer_res;
        }
        tab_token_multi_add(&(lexer_res.tab_token), ltken);
        line_num++;
    }
    //ft_printf("\n### LEXER\n\n");
    //print_tab_token(lexer_res.tab_token);
    if (lexer_res.tab_token.i < 0)
        lexer_res.er = 1;
    return lexer_res;
};
