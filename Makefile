ASM_NAME = asm
COREWAR_NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

INCLUDE_DIR = includes/
INCLUDE_FILES = op.h asm.h
INCLUDE_H = $(addprefix $(INCLUDEDIR), $(INCLUDE_FILES))


DIR_COMMON = srcs_common/
DIR_ASM = srcs_asm/
DIR_COREWAR = srcs_corewar/

C_FILES_NAMES_COMMON = op.c
C_FILES_NAMES_ASM = ast_to_byte.c cmd_input.c display_ast.c lexer.c \
	line_to_token.c main.c parser.c put_error.c tab_token.c
C_FILES_NAMES_COREWAR =

OBJDIR_COMMON = objs_common/
OBJ_COMMON = $(addprefix $(OBJDIR_COMMON), $(C_FILES_NAMES_COMMON:.c=.o))

OBJDIR_ASM = objs_asm/
OBJ_ASM = $(addprefix $(OBJDIR_ASM), $(C_FILES_NAMES_ASM:.c=.o))

OBJDIR_COREWAR = objs_corewar/
OBJ_COREWAR = $(addprefix $(OBJDIR_COREWAR), $(C_FILES_NAMES_COREWAR:.c=.o))


$(OBJDIR_COMMON)%.o: $(DIR_COMMON)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_COMMON)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(OBJDIR_ASM)%.o: $(DIR_ASM)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_ASM)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(OBJDIR_COREWAR)%.o: $(DIR_COREWAR)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_COREWAR)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(LIBFT):
	make -C $(LIBFTDIR) all

$(ASM_NAME): $(LIBFT) $(OBJ_ASM) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_ASM) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

$(COREWARE): $(LIBFT) $(OBJ_COREWAR) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_COREWAR) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

all: $(ASM_NAME) $(COREWAR_NAME)

clean:
	rm -f $(OBJDIR_COMMON)
	rm -f $(OBJDIR_ASM)
	rm -f $(OBJDIR_COREWAR)
	rm -rf *.dSYM
	make -C $(LIBFTDIR) clean

re: fclean all

fclean: clean
	rm -f $(ASM_NAME)
	rm -f $(COREWARE)
	make -C $(LIBFTDIR) fclean


.PHONY: all clean re fclean
