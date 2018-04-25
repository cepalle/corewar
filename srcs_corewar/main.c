/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 17:14:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 16:41:38 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"
#include <stdio.h>
#include "asm.h"

int 	main(void)
{
	ssize_t ret;
	t_header header;

//	malloc(MEM_SIZE);

	ret = read(0, &header, sizeof(t_header));
	if (ret == sizeof(t_header))
	{
		printf("si c'est possible\n");
	}
	else
		printf("non c'est pas possible\n");

	swap_4(&header.magic);
	printf("%x\n", header.magic);
	printf("%s\n", header.prog_name);
	swap_4(&header.prog_size);
	printf("%u\n", header.prog_size);
	printf("%s\n", header.comment);

	char *buffer_prog;

	buffer_prog = (char *)malloc(header.prog_size);

	read(0, buffer_prog, header.prog_size);

	unsigned int a;

	a = 0;
	while (a < header.prog_size)
	{
		printf("%0.2hhx ", buffer_prog[a]);
		a++;
	}

	char *pt_head;

	pt_head = (char *)&header;
	a = 0;

	printf("\n\n");

	while (a < sizeof(header))
	{
		printf("%0.2hhx ", pt_head[a]);
		a++;
	}

	return (0);
}


