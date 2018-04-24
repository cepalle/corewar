
#ifndef ASM_H
# define ASM_H

#include <stdlib.h>

# define TAB_TOKEN_LEN_INIT 4
# define LEN_LTOKEN 16
# define LABELS_DEC_LEN 8
# define MAX_PARAMS 3

enum TOKEN
{
    EMPTYY,                  // 0
    TOKEN_PROG_NAME,         // 1 .name                 data -> NULL
    TOKEN_PROG_COMMENT,      // 2 .comment              data -> NULL

    TOKEN_DIRECT_LABEL,      // 3 %:label               data -> label
    TOKEN_DIRECT_NUMBER,     // 4 %number               data -> number
    TOKEN_INDIRECT_LABEL,    // 5 :label                data -> label
    TOKEN_INDIRECT_NUMBER,   // 6 number                data -> number

    TOKEN_LABEL_DECLARATION, // 7 label:                data -> label
    TOKEN_LABEL,             // 8 label                 data -> label

    TOKEN_STRING,            // 9 "string",             data -> string
    TOKEN_COMMENT,           // 10 <#|;>comment\n       data -> comment
    TOKEN_SEPARATOR_CHAR,    // 11 ,                    data -> NULL
    TOKEN_EOL,               // 12 \n                   data -> NULL
};


// handel error, line and pos caractere.
struct s_token
{
	int file_pose_line;
	int file_pose_col;
    int er;
    int enum_token;
    char *data;
    int pose_octet_label_dec;
};
typedef struct s_token t_token;

struct s_tab_token
{
    int len;
    int i;
    t_token *tokens;
};
typedef struct s_tab_token t_tab_token;

struct s_lexer
{
    int er;
    t_tab_token tab_token;
};
typedef struct s_lexer t_lexer;

// CMD

struct s_cmdl
{
    int er;
    int fd;
    char opt_a;
    char *file_name;
};
typedef struct s_cmdl t_cmdl;

// PARSER

struct s_ast_inst
{
    int er;
    int nb_labels_dec;
    t_token labels_dec[LABELS_DEC_LEN];
    char *cmd;
    int nb_ast_params;
    t_token ast_params[MAX_PARAMS];
    struct s_ast_inst *next;
};
typedef struct s_ast_inst t_ast_inst;

struct s_ast_prog
{
    char *prog_name;
    char *prog_comment;
    t_ast_inst *ast_inst;
};
typedef struct s_ast_prog t_ast_prog;

struct s_parser
{
    int er;
    t_ast_prog ast_prog;
};
typedef struct s_parser t_parser;


t_cmdl cmd_input(int argc, char **argv);

t_lexer lexer(t_cmdl cmdl);

t_parser parser(t_lexer lexer_res);

void display_ast(t_parser parser_res);

void ast_to_byte(t_parser parser_res, char *file_name);

int put_error(char *msg);

int asm_usage(void);

void line_to_token(t_token *ltken, char **line, int *line_file, int fd);

void tab_token_multi_add(t_tab_token *tab_token, t_token *ltken);

void print_tab_token(t_tab_token tab_token);

void print_token(t_token token);

void ast_add_next(t_parser *parser_res, t_tab_token tab_token, int *i);

void print_ast_prog(t_ast_prog ast_prog);

int check_ast(t_parser parser_res);

int open_new_file(char *file_name);

unsigned prog_len(t_ast_inst *ast_inst);

int inst_len(t_ast_inst *ast_inst);

int len_param(int enum_token, char *cmd);

void write_header(int fd, t_parser parser_res);

void inst_feed_label_dec(t_ast_inst *ast_inst, int pos);

void insts_feed_label(t_parser parser_res, t_ast_inst *ast_inst);

void write_insts(int fd, t_ast_inst *ast_inst, int pos);

int check_registres(t_ast_inst *ast_inst);

int check_labels(t_parser parser_res, t_ast_inst *ast_inst);

int check_insts(t_ast_inst *inst);

void swap_4(unsigned int *to_swap);

void swap_2(unsigned short int *to_swap);

#endif
