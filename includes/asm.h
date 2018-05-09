/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   asm.h                                            .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/30 12:09:30 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 13:26:26 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include <stdlib.h>

# define TAB_TOKEN_LEN_INIT		4
# define LEN_LTOKEN				16
# define LABELS_DEC_LEN			16
# define MAX_PARAMS				3
# define LEN_INIT_FILES			4

/*
**	EMPTY,						0
**	TOKEN_PROG_NAME,			1 .name                 data -> NULL
**	TOKEN_PROG_COMMENT,			2 .comment              data -> NULL
**
**	TOKEN_DIRECT_LABEL,			3 %:label               data -> label
**	TOKEN_DIRECT_NUMBER,		4 %number               data -> number
**	TOKEN_INDIRECT_LABEL,		5 :label                data -> label
**	TOKEN_INDIRECT_NUMBER,		6 number                data -> number
**
**	TOKEN_LABEL_DECLARATION,	7 label:                data -> label
**	TOKEN_LABEL,				8 label                 data -> label
**
**	TOKEN_STRING,				9 "string",             data -> string
**	TOKEN_COMMENT,				10 <#|;>comment\n       data -> comment
**	TOKEN_SEPARATOR_CHAR,		11 ,                    data -> NULL
**	TOKEN_EOL,					12 \n                   data -> NULL
*/

enum						e_token
{
	EMPTY,
	TOKEN_PROG_NAME,
	TOKEN_PROG_COMMENT,
	TOKEN_DIRECT_LABEL,
	TOKEN_DIRECT_NUMBER,
	TOKEN_INDIRECT_LABEL,
	TOKEN_INDIRECT_NUMBER,
	TOKEN_LABEL_DECLARATION,
	TOKEN_LABEL,
	TOKEN_STRING,
	TOKEN_COMMENT,
	TOKEN_SEPARATOR_CHAR,
	TOKEN_EOL,
};

struct						s_token
{
	int						file_pose_line;
	int						file_pose_col;
	int						er;
	int						enum_token;
	char					*data;
	int						pose_octet_label_dec;
};
typedef struct s_token		t_token;

struct						s_tab_token
{
	int						len;
	int						i;
	t_token					*tokens;
};
typedef struct s_tab_token	t_tab_token;

struct						s_lexer
{
	int						er;
	char					**file;
	t_tab_token				tab_token;
};
typedef struct s_lexer		t_lexer;

/*
** CMD
*/

struct						s_cmdl
{
	int						er;
	int						fd;
	char					*file_name;
};
typedef struct s_cmdl		t_cmdl;

/*
** PARSER
*/

struct						s_ast_inst
{
	int						er;
	int						nb_labels_dec;
	t_token					labels_dec[LABELS_DEC_LEN];
	t_token					cmd;
	int						nb_ast_params;
	t_token					ast_params[MAX_PARAMS];
	struct s_ast_inst		*next;
};
typedef struct s_ast_inst	t_ast_inst;

struct						s_ast_prog
{
	char					*prog_name;
	char					*prog_comment;
	t_ast_inst				*ast_inst;
};
typedef struct s_ast_prog	t_ast_prog;

struct						s_parser
{
	int						er;
	t_ast_prog				ast_prog;
};
typedef struct s_parser		t_parser;

struct						s_file
{
	char					**file;
	int						*i_col;
	int						*i_line;
};
typedef struct s_file		t_file;

t_cmdl						cmd_input(int argc, char **argv);
t_lexer						lexer(t_cmdl cmdl);
t_parser					parser(t_lexer lexer_res);
void						ast_to_byte(t_parser parser_res, char *file_name);
void						ast_add_dote_start(t_parser *p, t_lexer l, int *i);
void						ast_add_inst(t_parser *p, t_lexer l, int *i);
void						ast_add_next(t_parser *p, t_lexer l, int *i);
int							asm_usage(void);
int							print_local_error
		(char **f, const int *ic, const int *il, char *m);
void						line_to_token(t_token *l, char **f, int *i);
void						tab_token_multi_add(t_tab_token *t, t_token *l);
void						print_tab_token(t_tab_token t);
void						print_token(t_token t);
void						print_ast_prog(t_ast_prog a);
int							check_ast(t_parser p, char **f);
int							check_registres(t_ast_inst *a, char **f);
int							check_labels(t_parser p, t_ast_inst *a, char **f);
int							check_insts(t_ast_inst *i, char **f);
int							open_new_file(char *file_name);
unsigned					prog_len(t_ast_inst *ast_inst);
int							inst_len(t_ast_inst *ast_inst);
int							len_param(int enum_token, char *cmd);
void						write_header(int fd, t_parser parser_res);
void						write_insts(int fd, t_ast_inst *ast_inst, int pos);
void						write_param(int f, t_token t, int d, int p);
void						inst_feed_label_dec(t_ast_inst *ast_inst, int pos);
void						insts_feed_label(t_parser p, t_ast_inst *a);
t_token						get_direct(int *i_line, char **file, int *i_col);
t_token						get_indirect_number(int *il, char **f, int *ic);
t_token						get_indirect_label(int *il, char **f, int *ic);
t_token						get_string(int *il, char **f, int *ic);
t_token						get_label(int *il, char **f, int *ic);
t_token						get_dote_start(int *il, char **f, int *ic);
t_token						get_separator_char(int *il, char **f, int *ic);
t_token						get_comment(int *il, char **f, int *ic);
void						print_tab_token(t_tab_token tab_token);
void						free_parser(t_parser parser_res);
void						free_lexer(t_lexer lexer_res);
void						inst_add_params(t_ast_inst *a, t_lexer l, int *i);

#endif
