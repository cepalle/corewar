# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2017/12/04 10:38:00 by cepalle      #+#   ##    ##    #+#        #
#    Updated: 2018/05/10 13:53:07 by cepalle     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME= libft.a
CC= gcc
CFLAGS= -Wall -Wextra -Werror

INCLUDEDIR=includes/
CFILENAME= ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_printf.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	pf_arg_c_to_str.c \
	pf_arg_di_to_str.c \
	pf_arg_not_type_to_str.c \
	pf_arg_oux_to_str.c \
	pf_arg_p_to_str.c \
	pf_arg_s_to_str.c \
	pf_arg_to_str.c \
	pf_choose_char.c \
	pf_format_atoi.c \
	pf_get_format.c \
	pf_get_format_flags.c \
	pf_get_format_type.c \
	pf_handler_format.c \
	pf_is_format.c \
	pf_is_num.c \
	pf_itoa.c \
	pf_memalloc.c \
	pf_memcpy.c \
	pf_not_arg_to_str.c \
	pf_padding_precision.c \
	pf_padding_width.c \
	pf_print_arg_c.c \
	pf_print_arg_i.c \
	pf_print_arg_oux.c \
	pf_print_arg_p.c \
	pf_print_arg_s.c \
	pf_print_flags.c \
	pf_print_not_arg.c \
	pf_print_not_type.c \
	pf_put_n_char.c \
	pf_put_wc.c \
	pf_putchar.c \
	pf_putstr.c \
	pf_strcpy.c \
	pf_strdup.c \
	pf_strlen.c \
	pf_strnew.c \
	pf_strrev.c \
	pf_wstrlen.c \
	ft_realloc.c \
	ft_isblank.c \
	ft_strndup.c \
	ft_queu.c \
	ft_free_tabchar.c \
	ft_lentabchar.c \
	ft_free_print_exit.c \
	ft_atoi_only.c \
	ft_itoa_base_ppichier.c

SRCDIR=srcs/
SRC=$(addprefix $(SRCDIR), $(CFILENAME))

OBJDIR=objs/
OBJ= $(addprefix $(OBJDIR), $(CFILENAME:.c=.o))

all:$(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(OBJDIR)%.o: $(SRCDIR)%.c $(INCLUDEDIR)/libft.h
	@mkdir -p $(OBJDIR)
	@$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDEDIR)

clean:
	rm -f $(OBJ)

re: fclean all

fclean: clean
	rm -f $(NAME)

.PHONY:all clean re fclean
