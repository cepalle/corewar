#include "asm.h"
#include "op.h"
#include "libft.h"
#include <unistd.h>

int len_param(int enum_token, char *cmd)
{
	if (enum_token == TOKEN_INDIRECT_LABEL ||
			enum_token == TOKEN_INDIRECT_NUMBER)
		return 2;
	if (enum_token == TOKEN_LABEL)
		return 1;
	return 2 + !get_op(cmd).dir_size_2 * 2;
};

int inst_len(t_ast_inst *ast_inst)
{
	int i;
	int len;

	i = 0;
	len = 1;
	len += get_op(ast_inst->cmd).octet_param;
	while (i < ast_inst->nb_ast_params)
	{
		len += len_param(ast_inst->ast_params[i].enum_token, ast_inst->cmd);
		i++;
	}
	return len;
};

void inst_feed_label_dec(t_ast_inst *ast_inst, int pos)
{
	int i;

	if (!ast_inst)
		return;
	i = 0;
	while (i < ast_inst->nb_labels_dec)
	{
		ast_inst->labels_dec[i].pos_octet_label_dec = pos;
		i++;
	}
	inst_feed_label_dec(ast_inst->next, pos + inst_len(ast_inst));
};

int open_new_file(char *file_name)
{
	int fd;

	// TODO
	(void) file_name;
	fd = 1;

	return fd;
};

unsigned prog_len(t_ast_inst *ast_inst)
{
	if (!ast_inst)
		return 0;
	return inst_len(ast_inst) + prog_len(ast_inst->next);
};

void write_header(int fd, t_parser parser_res)
{
	t_header header;

	ft_bzero(&header, sizeof(t_header));
	header.magic = COREWAR_EXEC_MAGIC;
	ft_strcpy(header.prog_name, parser_res.ast_prog.prog_name);
	header.prog_size = prog_len(parser_res.ast_prog.ast_inst);
	ft_strcpy(header.comment, parser_res.ast_prog.prog_comment);

	write(fd, &header, sizeof(t_header));
};

t_op get_op(char *cmd)
{
	int i;

	i = 0;
	while (i < OP_TAB_LENGTH)
	{
		if (ft_strcmp(gopt()[i].name, cmd))
			return gopt()[i];
		i++;
	}
	ft_printf("get_op cmd no found\n");
	return gopt()[OP_TAB_LENGTH];
}

void write_octet_param(int fd, t_ast_inst *ast_inst)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (i < ast_inst->nb_ast_params)
		{
			if (ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_NUMBER ||
					ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL)
				write(fd, "\10", 1); // TODO works?
			else if (ast_inst->ast_params[i].enum_token == TOKEN_LABEL)
				write(fd, "\01", 1);
			else
				write(fd, "\11", 1);
		}
		else
			write(fd, "\0", 1);
		i++;
	}
}

void write_param(int fd, t_token token, int dir_size_2, int pos)
{
	signed int to_write_4;
	signed short to_write_2;
	signed char t_write_1;

	if (token.enum_token == TOKEN_LABEL)
	{
		t_write_1 = (signed char)ft_atoi(token.data + 1);
		write(fd, &t_write_1, 1);
	}
	else if (token.enum_token == TOKEN_DIRECT_NUMBER)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short)ft_atoi(token.data);
			write(fd, &to_write_2, 2);
		}
		else
		{
			to_write_4 = ft_atoi(token.data);
			write(fd, &to_write_4, 4);
		}
	}
	else if (token.enum_token == TOKEN_DIRECT_LABEL)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short)(token.pos_octet_label_dec - pos);
			write(fd, &to_write_2, 2);
		}
		else
		{
			to_write_4 = token.pos_octet_label_dec - pos;
			write(fd, &to_write_4, 4);
		}
	}
	else if (token.enum_token == TOKEN_INDIRECT_NUMBER)
	{
		to_write_2 = (signed short)ft_atoi(token.data);
		write(fd, &to_write_2, 2);
	}
	else if (token.enum_token == TOKEN_INDIRECT_LABEL)
	{
		to_write_2 = (signed short)(token.pos_octet_label_dec - pos);
		write(fd, &to_write_2, 2);
	}
	ft_printf("write_param, tokem ennum not valide\n");
};

void write_params(int fd, t_ast_inst *ast_inst, int dir_size_2, int pos)
{
	int i;

	i = 0;
	while (i < ast_inst->nb_ast_params)
	{
		write_param(fd, ast_inst->ast_params[i], dir_size_2, pos);
		i++;
	}
};

void write_inst(int fd, t_ast_inst *ast_inst, int pos)
{
	t_op op;

	op = get_op(ast_inst->cmd);
	write(fd, &op.opcode, 1);
	if (op.octet_param)
		write_octet_param(fd, ast_inst);
	write_params(fd, ast_inst, op.dir_size_2, pos);
};

void write_insts(int fd, t_ast_inst *ast_inst, int pos)
{
	if (!ast_inst)
		return;
	write_inst(fd, ast_inst, pos);
	write_insts(fd, ast_inst->next, pos + inst_len(ast_inst));
};

void ast_to_byte(t_parser parser_res, char *file_name)
{
	int fd;

	fd = open_new_file(file_name);
	if (fd < 0)
		return;
	inst_feed_label_dec(parser_res.ast_prog.ast_inst, 0);
	// TODO inst_feed_label(parser_res.ast_prog.ast_inst, 0);
	write_header(fd, parser_res);
	write_insts(fd, parser_res.ast_prog.ast_inst, 0);
};
