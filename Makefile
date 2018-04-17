ASM_NAME = asm
COREWAR_NAME = corewar

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR), libft.a)
INCLUDEDIR_LIBFT = $(addprefix $(LIBFTDIR), includes/)

INCLUDE_DIR_COMMON = includes_common/
INCLUDE_FILES_COMMON = op.h
INCLUDE_H_COMMON = $(addprefix $(INCLUDEDIR), $(INCLUDE_FILES))


C_FILES_NAMES_COMMON =
C_FILES_NAMES_ASM =
C_FILES_NAMES_COREWAR =




