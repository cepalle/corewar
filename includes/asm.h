enum TOKEN
{
		TOKEN_PROG_NAME,      // .name                 data -> NULL
		TOKEN_PROG_COMMENT,   // .comment              data -> NULL
		TOKEN_OP_NAME,        // see g_op_tab in op.c, data -> op_name
		TOKEN_LABEL,          // label,                data -> label
		TOKEN_NUMBER,         // number,               data -> number
		TOKEN_STRING,         // " * ",                data -> string
		TOKEN_COMMENT,        // '#' * \n              data -> comment
		TOKEN_LABEL_CHAR,     // :                     data -> NULL
		TOKEN_MINUS,          // -                     data -> NULL
		TOKEN_PLUS,           // +                     data -> NULL
		TOKEN_DIRECT_CHAR,    // %                     data -> NULL
		TOKEN_SEPARATOR_CHAR, // ,                     data -> NULL
		TOKEN_EOL,            // \n                    data -> NULL
};

struct s_token
{
		int er;
		int token;
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

struct s_cmdl
{
		int er;
		int fd;
		char opt_a;
};
typedef struct s_cmdl t_cmdl;

struct s_parser
{
		int er;
};
typedef struct s_parser t_parser;





int put_error(char *msg);
t_cmdl cmd_input(int argc, char **argv);
t_lexer lexer(int fd);
t_parser parser(void);
void display_ast(void);
void ast_to_byte(void);
void line_to_token(t_token *ltken);
void tab_token_multi_add(t_lexer *lexer_res, t_token *ltken);





