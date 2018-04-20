// LEXER

#define TAB_TOKEN_LEN_INIT 4
#define LEN_LTOKEN 16


enum TOKEN
{
    EMPTYY,
		TOKEN_PROG_NAME,         // .name                 data -> NULL
		TOKEN_PROG_COMMENT,      // .comment              data -> NULL

		TOKEN_DIRECT_LABEL,      // %:label               data -> label
		TOKEN_DIRECT_NUMBER,     // %number               data -> number
		TOKEN_INDIRECT_NUMBER,	 // :label                data -> label
		TOKEN_INDIRECT_LABEL,    // number                data -> number
		TOKEN_LABEL_DECLARATION, // label:                data -> label
		TOKEN_LABEL,             // label                 data -> label

		TOKEN_STRING,            // "string",             data -> string
		TOKEN_COMMENT,           //  <#|;>comment\n       data -> comment
		TOKEN_SEPARATOR_CHAR,    // ,                     data -> NULL
		TOKEN_EOL,               // \n                    data -> NULL
};

struct s_token
{
		int er;
		int enum_token;
		char *data;
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
};
typedef struct s_cmdl t_cmdl;

// PARSER

struct s_ast_param
{
	  int enum_toekn;
		char *data;
};
typedef struct s_ast_param t_ast_param;

struct s_ast_inst
{
		int er;
		int nb_label;
		char label[8];
	  int opcode;
		int nb_ast_param;
		t_ast_param ast_param[3];
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
void ast_to_byte(t_parser parser_res);

int put_error(char *msg);
int asm_usage(void);
void line_to_token(t_token *ltken, char *line, int line_file);
void tab_token_multi_add(t_tab_token *tab_token, t_token *ltken);
void print_tab_token(t_tab_token tab_token);
void ast_add_next(t_parser *parser_res, t_tab_token tab_token, int *i);
void print_tab_token(t_tab_token tab_token);




