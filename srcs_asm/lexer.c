#include "../includes/asm.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>


t_lexer lexer(int fd)
{
    t_lexer lexer_res;
    t_token ltken[LEN_LTOKEN];
    char *line;
    int line_num;

    ft_bzero(&lexer_res, sizeof(t_lexer));
    ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
    line_num = 0;
    while (get_next_line(fd, &line) > 0)
    {
        line_to_token(ltken, line, line_num);
        //ft_printf("----line: %s\n", line);
        free(line);
        if (ltken[0].er)
        {
            //free
            close(fd);
            lexer_res.er = 1;
            return lexer_res;
        }
        tab_token_multi_add(&(lexer_res.tab_token), ltken);
        line_num++;
        //print_tab_token(lexer_res.tab_token); // TEST
    }
    print_tab_token(lexer_res.tab_token); // TEST
    return lexer_res;
};
