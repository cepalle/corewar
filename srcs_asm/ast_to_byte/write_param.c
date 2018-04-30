#include "asm.h"
#include "libft.h"
#include "op.h"
#include <unistd.h>

void		write_param(int fd, t_token token, int dir_size_2, int pos)
{
	signed int		to_write_4;
	signed short	to_write_2;
	signed char		t_write_1;

	if (token.enum_token == TOKEN_LABEL)
	{
		t_write_1 = (signed char)ft_atoi(token.data + 1);
		write(fd, &t_write_1, 1);
		return ;
	}
	else if (token.enum_token == TOKEN_DIRECT_NUMBER)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short)ft_atoi(token.data);
			swap_2((unsigned short *)&to_write_2);
			write(fd, &to_write_2, 2);
			return ;
		}
		else
		{
			to_write_4 = ft_atoi(token.data);
			swap_4((unsigned int *)&to_write_4);
			write(fd, &to_write_4, 4);
			return ;
		}
	}
	else if (token.enum_token == TOKEN_DIRECT_LABEL)
	{
		if (dir_size_2)
		{
			to_write_2 = (signed short)(token.pose_octet_label_dec - pos);
			swap_2((unsigned short *)&to_write_2);
			write(fd, &to_write_2, 2);
			return ;
		}
		else
		{
			to_write_4 = token.pose_octet_label_dec - pos;
			swap_4((unsigned int *)&to_write_4);
			write(fd, &to_write_4, 4);
			return ;
		}
	}
	else if (token.enum_token == TOKEN_INDIRECT_NUMBER)
	{
		to_write_2 = (signed short)ft_atoi(token.data);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
		return ;
	}
	else if (token.enum_token == TOKEN_INDIRECT_LABEL)
	{
		to_write_2 = (signed short)(token.pose_octet_label_dec - pos);
		swap_2((unsigned short *)&to_write_2);
		write(fd, &to_write_2, 2);
		return ;
	}
	ft_printf("Unexcepted error: 3\n");
	print_token(token);
	ft_printf("\n");
}
