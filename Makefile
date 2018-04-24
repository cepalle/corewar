ASM_NAME = asm
COREWAR_NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

INCLUDE_DIR = includes/
INCLUDE_FILES = op.h asm.h
INCLUDE_H = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))


DIR_COMMON = srcs_common/
DIR_ASM = srcs_asm/
DIR_COREWAR = srcs_corewar/

C_FILES_NAMES_COMMON = op.c
C_FILES_NAMES_ASM = ast_to_byte.c cmd_input.c display_ast.c lexer.c \
	line_to_token.c main.c parser.c put_error.c tab_token.c \
	check_ast.c ast_handler.c feed_label.c len_prog.c open_new_file.c \
	write_header.c write_insts.c check_labels.c check_registres.c \
	check_insts.c swap_char.c
C_FILES_NAMES_COREWAR = main.c

OBJDIR_COMMON = objs_common/
OBJ_COMMON = $(addprefix $(OBJDIR_COMMON), $(C_FILES_NAMES_COMMON:.c=.o))

OBJDIR_ASM = objs_asm/
OBJ_ASM = $(addprefix $(OBJDIR_ASM), $(C_FILES_NAMES_ASM:.c=.o))

OBJDIR_COREWAR = objs_corewar/
OBJ_COREWAR = $(addprefix $(OBJDIR_COREWAR), $(C_FILES_NAMES_COREWAR:.c=.o))

# OBJ

$(OBJDIR_COMMON)%.o: $(DIR_COMMON)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_COMMON)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(OBJDIR_ASM)%.o: $(DIR_ASM)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_ASM)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

$(OBJDIR_COREWAR)%.o: $(DIR_COREWAR)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_COREWAR)
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

# BIN

# ADD libft_file in dependance ?
$(LIBFT):
	make -C $(LIBFTDIR) all

$(ASM_NAME): $(LIBFT) $(OBJ_ASM) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_ASM) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

$(COREWAR_NAME): $(LIBFT) $(OBJ_COREWAR) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_COREWAR) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

# REGLE

all: $(ASM_NAME) $(COREWAR_NAME)

clean:
	rm -rf $(OBJDIR_COMMON)
	rm -rf $(OBJDIR_ASM)
	rm -rf $(OBJDIR_COREWAR)
	rm -rf *.dSYM
	make -C $(LIBFTDIR) clean

re: fclean all

re_asm: fclean_not_lib $(ASM_NAME)

re_corewar: fclean_not_lib $(COREWAR_NAME)

fclean: clean
	rm -f $(ASM_NAME)
	rm -f $(COREWAR_NAME)
	make -C $(LIBFTDIR) fclean

fclean_not_lib: clean
	rm -f $(ASM_NAME)
	rm -f $(COREWAR_NAME)

.PHONY: all clean re fclean

test:
	make re_asm && ./asm champs/examples/bee_gees.s && hexdump -C champs/examples/bee_gees.cor && echo "----------" && hexdump -C champs/examples/bee_gees_sav.cor

