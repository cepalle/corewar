ASM_NAME = asm
COREWAR_NAME = corewar

NB_DUMP = 128
CHAMP1 = ./champs/zork
CHAMP2 = ./champs/zork
CHAMP3 = ./champs/zork
CHAMP4 = ./champs/zork

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/
LIBFTDIR_SRCS = libft/srcs/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

LIBFT_FILES_C_NAME = ft_atoi.c \
    ft_atoi_only.c \
    ft_bzero.c \
    ft_free_print_exit.c \
    ft_free_tabchar.c \
    ft_isalnum.c \
    ft_isalpha.c \
    ft_isascii.c \
    ft_isblank.c \
    ft_isdigit.c \
    ft_isprint.c \
    ft_itoa.c \
    ft_itoa_base_ppichier.c \
    ft_lentabchar.c \
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
    ft_queu.c \
    ft_realloc.c \
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
    ft_strndup.c \
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
    pf_wstrlen.c

LIBFT_FILES_C = $(addprefix libft/srcs/, $(LIBFT_FILES_C_NAME))

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
    cal_pc_add.c \
    vm_free.c \
    do_op.c

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
	parser/inst_add_params.c \
	print/print_ast.c \
	print/print_error.c \
	print/print_tab_token.c \
	cmd_input.c \
	main.c

C_FILES_NAMES_COREWAR = main.c \
    input_cmdline.c \
    input_cmdline_option.c \
    input_cmdline_player.c \
    ft_str_is_digit.c \
    ft_usage.c \
    proc_exec.c \
    vm_cycle.c \
    cmd_save_init.c \
    cmd_save_check_error.c \
    cmd_save_oct_params.c \
    vm_init.c \
    generate_nb.c \
    vm_print.c \
    vm_run.c \
    input_free.c \
    header_print.c \
    vm_dump_mem.c \
    proc_handler.c \
    display_win.c

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

$(LIBFT): libft/includes/libft.h $(LIBFT_FILES_C)
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
	rm -rf *.cor
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
	@./asm $(CHAMP1).s > /dev/null
	@mv $(CHAMP1).cor tmp1.cor
	@./bin_ref/asm $(CHAMP1).s > /dev/null
	@mv $(CHAMP1).cor tmp1r.cor
	@./asm $(CHAMP2).s > /dev/null
	@mv $(CHAMP2).cor tmp2.cor
	@./bin_ref/asm $(CHAMP2).s > /dev/null
	@mv $(CHAMP2).cor tmp2r.cor

diff_corewar: make_test
	@./bin_ref/corewar tmp1r.cor tmp2r.cor -d $(NB_DUMP) | grep -a "0x0" > test_ref || true
	@./corewar tmp1.cor tmp2.cor -dl $(NB_DUMP) | grep -a "0x0" > test_my || true
	@rm -f tmp1.cor tmp2.cor tmp1r.cor tmp2r.cor
	diff test_ref test_my

diff_all_turn: make_test
	sh ./test_corewar/test.sh $(CHAMP1).cor $(CHAMP2).cor $(NB_DUMP)

.PHONY: all clean re fclean make_test
