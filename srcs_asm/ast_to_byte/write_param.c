/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   write_param.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/02 10:37:03 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/02 10:37:06 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "asm.h"
#include "libft.h"
#include "op.h"
#include <unistd.h>

static void	write_reg(int fd, t_token token)
{
	signed char		t_write_1;

	t_write_1 = (signed char)ft_atoi(token.data + 1);
	write(fd, &t_write_1, 1);
}

static void	write_direct_number(int fd, t_token token, int dir_size_2)
{
	signed int		to_write_4;
	signed short	to_write_2;

	if (dir_size_2)
	{
		to_write_2 = (signed short)ft_atoi(token.data);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
	}
	else
	{
		to_write_4 = ft_atoi(token.data);
		swap_4((unsigned int *)&to_write_4);
		write(fd, &to_write_4, 4);
	}
}

static void	write_direct_label(int fd, t_token token, int dir_size_2, int pos)
{
	signed short	to_write_2;
	signed int		to_write_4;

	if (dir_size_2)
	{
		to_write_2 = (signed short)(token.pose_octet_label_dec - pos);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
	}
	else
	{
		to_write_4 = token.pose_octet_label_dec - pos;
		swap_4((unsigned int *)&to_write_4);
		write(fd, &to_write_4, 4);
	}
}

static void	write_indirect_number(int fd, t_token token)
{
	signed short	to_write_2;

	to_write_2 = (signed short)ft_atoi(token.data);
	swap_2((unsigned short *)&to_write_2);
	write(fd, &to_write_2, 2);
}

void		write_param(int fd, t_token token, int dir_size_2, int pos)
{
	signed short	to_write_2;

	if (token.enum_token == TOKEN_LABEL)
		write_reg(fd, token);
	else if (token.enum_token == TOKEN_DIRECT_NUMBER)
		write_direct_number(fd, token, dir_size_2);
	else if (token.enum_token == TOKEN_DIRECT_LABEL)
		write_direct_label(fd, token, dir_size_2, pos);
	else if (token.enum_token == TOKEN_INDIRECT_NUMBER)
		write_indirect_number(fd, token);
	else if (token.enum_token == TOKEN_INDIRECT_LABEL)
	{
		to_write_2 = (signed short)(token.pose_octet_label_dec - pos);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
	}
	else
	{
		ft_printf("Unexcepted error: 3\n");
		print_token(token);
		ft_printf("\n");
	}
}
