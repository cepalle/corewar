ASM_NAME = asm
COREWAR_NAME = corewar

NB_DUMP = 1

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

INCLUDE_DIR = includes/
INCLUDE_FILES = op.h asm.h corewar.h
INCLUDE_H = $(addprefix $(INCLUDE_DIR), $(INCLUDE_FILES))


DIR_COMMON = srcs_common/
DIR_ASM = srcs_asm/
DIR_COREWAR = srcs_corewar/

C_FILES_NAMES_COMMON = op.c swap_char.c \
    cmd/add.c \
    cmd/aff.c \
    cmd/and.c \
    cmd/fork.c \
    cmd/ld.c \
    cmd/ldi.c \
    cmd/lfork.c \
    cmd/live.c \
    cmd/lld.c \
    cmd/lldi.c \
    cmd/or.c \
    cmd/st.c \
    cmd/sti.c \
    cmd/sub.c \
    cmd/xor.c \
    cmd/zjmp.c \
    param_handler.c \
    vm_read.c \
    vm_write.c \
    vm_fork.c \
    cal_pc_add.c

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

C_FILES_NAMES_COREWAR = main.c \
    input_cmdline.c \
    ft_str_is_digit.c \
    ft_usage.c \
    proc_exec.c \
    vm_cycle.c \
    cmd_save_init.c \
    vm_init.c \
    vm_print.c \
    vm_run.c \
    vm_free.c \
    input_free.c \
    header_print.c \
    vm_dump_mem.c \
    player_handler.c

OBJDIR_COMMON = objs_common/
OBJ_COMMON = $(addprefix $(OBJDIR_COMMON), $(C_FILES_NAMES_COMMON:.c=.o))

OBJDIR_ASM = objs_asm/
OBJ_ASM = $(addprefix $(OBJDIR_ASM), $(C_FILES_NAMES_ASM:.c=.o))

OBJDIR_COREWAR = objs_corewar/
OBJ_COREWAR = $(addprefix $(OBJDIR_COREWAR), $(C_FILES_NAMES_COREWAR:.c=.o))

# OBJ

all: $(ASM_NAME) $(COREWAR_NAME)

$(OBJDIR_COMMON)%.o: $(DIR_COMMON)%.c $(INCLUDE_H)
	@mkdir -p $(OBJDIR_COMMON)
	@mkdir -p $(OBJDIR_COMMON)/cmd
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
	@mkdir -p $(OBJDIR_COREWAR)/cmd
	$(CC) -c $< $(CFLAGS) -o $@ -I $(INCLUDE_DIR) -I $(INCLUDEDIR_LIBFT)

# BIN

# ADD libft_file in dependance ?
$(LIBFT):
	make -C $(LIBFTDIR) all

# TO CHANGE OBJ_COREWARE
$(ASM_NAME): $(LIBFT) $(OBJ_ASM) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_ASM) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

$(COREWAR_NAME): $(LIBFT) $(OBJ_COREWAR) $(OBJ_COMMON)
	$(CC) $(CFLAGS) -o $@ $(OBJ_COREWAR) $(OBJ_COMMON) -L./$(LIBFTDIR) -lft

# REGLE

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

make_test:
	./bin_ref/asm ./champs/examples/my_test.s
	./bin_ref/asm ./champs/examples/my_scnd_test.s
	@make corewar

test1_corewar: make_test
	./corewar -n 333333333 ./champs/examples/my_scnd_test.cor -n 2222222 ./champs/examples/my_test.cor -d $(NB_BUMP)

test1_diff: make_test
	./bin_ref/corewar ./champs/examples/my_test.cor ./champs/examples/my_scnd_test.cor -d $(NB_DUMP) | grep "0x0" > test_ref || true
	./corewar ./champs/examples/my_test.cor ./champs/examples/my_scnd_test.cor -d $(NB_DUMP) | grep "0x0" > test_my || true
	diff test_ref test_my

test_all_turn: make_test
	sh ./test_corewar/test.sh $(NB_DUMP)

.PHONY: all clean re fclean make_test
