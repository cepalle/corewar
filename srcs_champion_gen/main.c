/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/05/04 14:13:17 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/05/04 14:13:18 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "op.h"
#include "libft.h"
#include "gen_champ.h"
#include <unistd.h>

unsigned char		*set_prog(unsigned int size)
{
	unsigned char	*prog;

	prog = ft_memalloc(size * sizeof(unsigned char));
	prog[0] = 0x01;
	prog[1] = 0x01;
	prog[2] = 0x01;
	prog[3] = 0x01;
	prog[4] = 0x01;
	prog[5] = 0x01;
	prog[6] = 0x01;
	prog[7] = 0x01;
	prog[8] = 0x01;
	prog[9] = 0x01;
	prog[10] = 0x01;
	prog[11] = 0x01;
	prog[12] = 0x01;
	prog[13] = 0x01;
	prog[14] = 0x01;
	prog[15] = 0x01;
	return (prog);
}


void	write_prog(t_header *head, char *prog)
{
	int		fd;

	fd = open("bad.cor", O_CREAT | O_RDWR, S_IRWXU | S_IRWXG | S_IRWXO);
	if (fd < 0)
	{
		ft_printf("Unexpected error, can't write the file.cor\n");
		return ;
	}
	swap_4(&head->magic);
	swap_4(&head->prog_size);
	write(fd, &head, sizeof(t_header));
	// TODO
	return (fd);
}

unsigned int		main(int argc, char **argv)
{
	t_header head;
	char	*prog;

	ft_bzero(&head, sizeof(t_header));
	head.prog_name = "bad champ";
	head.comment = "usless comment";
	head.magic =
	head.prog_size = 256;
	prog = set_prog(head.prog_size);
	write_prog(&head, prog);
	return (0);
}
