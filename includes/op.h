/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 10:43:23 by ppichier    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef OP_H
# define OP_H

/*
** Toutes les tailles sont en octets.
** On part du principe qu'un int fait 32 bits. Est-ce vrai chez vous ?
*/

# define IND_SIZE	2
# define REG_SIZE	1
# define DIR_SIZE	4

# define REG_CODE	1
# define DIR_CODE	2
# define IND_CODE	3

# define MAX_ARGS_NUMBER	4
# define MAX_PLAYERS		4
# define MEM_SIZE			(4*1024)
# define IDX_MOD			(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE		(MEM_SIZE / 6)

# define COMMENT_CHAR		'#'
# define LABEL_CHAR			':'
# define DIRECT_CHAR		'%'
# define SEPARATOR_CHAR		','

# define LABEL_CHARS	"abcdefghijklmnopqrstuvwxyz_0123456789"

# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define REG_NUMBER		16

# define CYCLE_TO_DIE	1536
# define CYCLE_DELTA	50
# define NBR_LIVE		21
# define MAX_CHECKS		10

/*
** OP_TAB
*/

# define OP_TAB_LENGTH	16

typedef char			t_arg_type;

# define T_REG	0b001
# define T_DIR	0b010
# define T_IND	0b100
# define T_LAB	8

/*
** HEADER
*/

# define PROG_NAME_LENGTH	(128)
# define COMMENT_LENGTH		(2048)
# define COREWAR_EXEC_MAGIC	0xea83f3

struct					s_header
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
};
typedef struct s_header	t_header;

/*
** OP
*/

struct					s_op
{
	char				*name;
	int					nb_arg;
	int					args[3];
	char				opcode;
	int					cycle;
	char				*descr;
	int					octet_param;
	int					dir_size_2;
	void				*op_fct;
	int					default_len;
	int					carry;
};
typedef struct s_op		t_op;

t_op					*gopt(void);
t_op					get_op_name(char *cmd);
void					swap_4(unsigned int *to_swap);
void					swap_2(unsigned short int *to_swap);
t_op					get_op_cmd(int opcode);

#endif
