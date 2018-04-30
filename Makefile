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

C_FILES_NAMES_COMMON = op.c swap_char.c
C_FILES_NAMES_ASM = ast_to_byte/ast_to_byte.c \
	ast_to_byte/feed_label.c \
	ast_to_byte/len_prog.c \
	ast_to_byte/open_new_file.c \
	ast_to_byte/write_header.c \
	ast_to_byte/write_insts.c \
	ast_to_byte/write_param.c \
	lexer/lexer.c \
	lexer/line_to_token.c \
	lexer/tab_token.c \
	lexer/get_comment_sep.c \
	lexer/get_direct.c \
	lexer/get_dote_start.c \
	lexer/get_indirect.c \
	lexer/get_label.c \
	lexer/get_string.c \
	lexer/free_lexer.c \
	parser/ast_add_next.c \
	parser/check_ast.c \
	parser/check_insts.c \
	parser/check_labels.c \
	parser/check_registres.c \
	parser/parser.c \
	parser/ast_add_inst.c \
	parser/ast_dote_start.c \
	parser/free_parser.c \
	print/print_ast.c \
	print/print_error.c \
	print/print_tab_token.c \
	cmd_input.c \
	main.c

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
	@mkdir -p $(OBJDIR_ASM)/ast_to_byte
	@mkdir -p $(OBJDIR_ASM)/lexer
	@mkdir -p $(OBJDIR_ASM)/parser
	@mkdir -p $(OBJDIR_ASM)/print
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

