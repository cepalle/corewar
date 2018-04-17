#include "../includes/asm.h"
#include "../libft/includes/libft.h"
#include <unistd.h>

t_lexer lexer(int fd) {
    t_lexer lexer_res;
    t_token ltken[16];
    char *line;

    ft_bzero(lexer_res, sizeof(t_lexer));
    ft_bzero(ltken, sizeof(t_token) * 5);
    while (get_next_line(fd, &line) > 0)
    {
        line_to_token(ltken);
        !ltken[0].er && tab_token_multi_add(&lexer_res, ltoken);
        if (lexer_res.er)
        {
            //free
            close(fd);
            return lexer_res;
        }
    }
    return lexer_res;
};
