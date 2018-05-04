NAME = gen_champ

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = ../libft/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

C_FILES_NAMES = main.c \
    swap_char.c

OBJDIR = objs/
OBJ = $(addprefix $(OBJDIR), $(C_FILES_NAMES:.c=.o))

INCLUDE_DIR= ../includes/

all: $(NAME)

$(OBJDIR)%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) -o $@ $(OBJ) -L./$(LIBFTDIR) -lft

clean:
	rm -rf $(OBJDIR)
	make -C $(LIBFTDIR) clean

re: fclean all

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFTDIR) fclean

.PHONY: all clean re fclean
