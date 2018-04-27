#include "asm.h"
#include "libft.h"
#include "op.h"
#include <unistd.h>

void write_octet_param(int fd, t_ast_inst *ast_inst)
{
	int i;
	unsigned char codect;

	i = 0;
	codect = 0;
	while (i < ast_inst->nb_ast_params)
	{
		if (ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_NUMBER ||
		    ast_inst->ast_params[i].enum_token == TOKEN_DIRECT_LABEL)
			codect |= (0b10 << ((3 - i) * 2));
		else if (ast_inst->ast_params[i].enum_token == TOKEN_LABEL)
			codect |= (0b01 << ((3 - i) * 2));
		else
			codect |= (0b11 << ((3 - i) * 2));
		i++;
	}
	write(fd, &codect, 1);
	//ft_printf("codect: %hhd\n", codect);
}

void write_param(int fd, t_token token, int dir_size_2, int pos)
{
	signed int to_write_4;
	signed short to_write_2;
	signed char t_write_1;

	if (token.enum_token == TOKEN_LABEL)
	{
		t_write_1 = (signed char) ft_atoi(token.data + 1);
		write(fd, &t_write_1, 1);
		return;
	}
	else if (token.enum_token == TOKEN_DIRECT_NUMBER)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short) ft_atoi(token.data);
			//ft_printf("atoi: %hd, data: '%s'\n", to_write_2, token.data);
			swap_2((unsigned short *)&to_write_2);
			write(fd, &to_write_2, 2);
			return;
		}
		else
		{
			to_write_4 = ft_atoi(token.data);
			swap_4((unsigned int *)&to_write_4);
			write(fd, &to_write_4, 4);
			return;
		}
	}
	else if (token.enum_token == TOKEN_DIRECT_LABEL)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short) (token.pose_octet_label_dec - pos);
			swap_2((unsigned short *)&to_write_2);
			write(fd, &to_write_2, 2);
			return;
		}
		else
		{
			to_write_4 = token.pose_octet_label_dec - pos;
			swap_4((unsigned int *)&to_write_4);
			write(fd, &to_write_4, 4);
			return;
		}
	}
	else if (token.enum_token == TOKEN_INDIRECT_NUMBER)
	{
		to_write_2 = (signed short) ft_atoi(token.data);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
		return;
	}
	else if (token.enum_token == TOKEN_INDIRECT_LABEL)
	{
		to_write_2 = (signed short) (token.pose_octet_label_dec - pos);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
		return;
	}
	ft_printf("write_param, tokem ennum not valide\n");
	print_token(token);
	ft_printf("\n");
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

	if (!ast_inst->cmd.enum_token)
		return;
	op = get_op(ast_inst->cmd.data);
	write(fd, &op.opcode, 1);
	//ft_printf("cmd: %s, opcode: %d\n", ast_inst->cmd, op.opcode);
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
