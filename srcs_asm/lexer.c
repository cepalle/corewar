#include "../includes/asm.h"
#include "../libft/includes/libft.h"
#include <unistd.h>
#include <stdlib.h>

#define LEN_LTOKEN 16

t_lexer lexer(int fd) {
    t_lexer lexer_res;
    t_token ltken[LEN_LTOKEN];
    char *line;

    ft_bzero(&lexer_res, sizeof(t_lexer));
    ft_bzero(ltken, sizeof(t_token) * LEN_LTOKEN);
    while (get_next_line(fd, &line) > 0)
    {
        line_to_token(ltken, line);
        free(line);
        if (!ltken[0].er)
            tab_token_multi_add(&(lexer_res.tab_token), ltken);
        if (ltken[0].er)
        {
            //free
            close(fd);
            lexer_res.er = 1;
            return lexer_res;
        }
    }
    return lexer_res;
};
