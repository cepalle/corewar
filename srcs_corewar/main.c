/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/17 17:14:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 15:30:11 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "op.h"
#include "corewar.h"
#include <stdio.h>
#include "asm.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"

void	ft_usage(void)
{
	ft_printf("ft_usage\n");

	ft_printf("Usage: ./corewar [-d N -s N -v N | -b --stealth | -n --stealth] [-a] <champion1.cor> <...>\n"
					  "    -a        : Prints output from \"aff\" (Default is to hide it)\n"
					  "#### TEXT OUTPUT MODE ##########################################################\n"
					  "    -d N      : Dumps memory after N cycles then exits\n"
					  "    -s N      : Runs N cycles, dumps memory, pauses, then repeats\n"
					  "    -v N      : Verbosity levels, can be added together to enable several\n"
					  "                - 0 : Show only essentials\n"
					  "                - 1 : Show lives\n"
					  "                - 2 : Show cycles\n"
					  "                - 4 : Show operations (Params are NOT litteral ...)\n"
					  "                - 8 : Show deaths\n"
					  "                - 16 : Show PC movements (Except for jumps)\n"
					  "#### BINARY OUTPUT MODE ########################################################\n"
					  "    -b        : Binary output mode for corewar.42.fr\n"
					  "    --stealth : Hides the real contents of the memory\n"
					  "#### NCURSES OUTPUT MODE #######################################################\n"
					  "    -n        : Ncurses output mode\n"
					  "    --stealth : Hides the real contents of the memory\n"
					  "################################################################################");
}


int 	ft_check_player(char *argv)
{
	int ret;
	size_t len;

	ft_printf("ft_check_player\n");

	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp( argv + (len - 4), ".cor", 4) != 0)))
	{
		ft_printf("%s n'est pas un champion\n", argv);
		return (0);
	}
	ret = open(argv, O_RDONLY);
	if (ret == -1)
	{
		ft_printf("fichier inexistant\n");
		return (0);
	}
	close(ret);
	ft_printf("%s est bien un champion\n", argv);
	return (1);
}

int 	ft_check_option(char *argv)
{
	ft_printf("ft_check_option\n");
//	TODO: penser a choisir les options que l'on va mettre en place
	if (ft_strcmp(argv, "-n") == 0)
	{
		ft_printf("Ncurses output mode\n");
		return (1);
	}
	if (ft_strcmp(argv, "-a") == 0)
	{
		ft_printf("Prints output from \"aff\" (Default is to hide it)\n");
		return (1);
	}
	if (ft_strcmp(argv, "-b") == 0)
	{
		ft_printf("Binary output mode for corewar.42.fr\n");
		return (1);
	}
	ft_printf("option non reconnue\n");
	return (0);
}

int 	ft_check_arg(char **argv)
{
	int a;

	ft_printf("ft_check_arg\n");
	a = 1;
	while (argv[a])
	{
		if (ft_check_option(argv[a]) == 0 && ft_check_player(argv[a]) == 0)
		{
			ft_printf("Can't read source file %s\n", argv[a]);
			return (0);
		}
		a++;
	}
	return (1);
}

int		ft_count_player(char ** argv)
{
	int a;
	size_t len;
	int count;

	ft_printf("ft_count_player\n");
	a = 1;
	count = 0;
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ft_strncmp( argv[a] + (len - 4), ".cor", 4) == 0)
		{
			ft_printf("%s est un champion\n", argv[a]);
			count++;
		}
		a++;
	}
	if (count == 0)
		ft_printf("aucun champion trouve\n");
	return (count++);
}

int		ft_check_error(int argc, char **argv)
{
	ft_printf("ft_check_error\n");
	if (argc == 1 || ft_count_player(argv) == 0)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_arg(argv) == 0)
		return (0);
	return (1);
}














void	ft_fill_player(char *argv, t_vm *vm, int num_player)
{
	int fd;
	ssize_t	ret;


	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_printf("erreur ouverture fd\n");



	ret = read(fd, &vm->player[num_player].head, sizeof(t_header));
	if (ret == sizeof(t_header))
		ft_printf("j'ai cree le header du joueur\n");

//	nb magic code sur 4 octet pour lire en int il faut reverse
	swap_4(&vm->player[num_player].head.magic);
	
	ft_printf("%x\n", vm->player[num_player].head.magic);
	ft_printf("%s\n", vm->player[num_player].head.prog_name);





//	nb code sur 4 octet a swap pour lire bon nombre
	swap_4(&vm->player[num_player].head.prog_size);

	ft_printf("%u\n", vm->player[num_player].head.prog_size);
	ft_printf("%s\n", vm->player[num_player].head.comment);
}















void	ft_create_player(char **argv, t_vm *vm)
{
	int a;
	int num_player;
	size_t len;

	a = 1;
	num_player = 0;
	vm->nb_p = ft_count_player(argv);
	if(!(vm->player = malloc(sizeof(t_player) * vm->nb_p)))
		return ;
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ft_strncmp( argv[a] + (len - 4), ".cor", 4) == 0)
		{
			ft_printf("je vais traveiller sur le joueur %s\n", argv[a]);
			ft_fill_player(argv[a], vm, num_player);
			num_player++;
		}
		a++;
	}

}

/*void	ft_create_map(t_vm *vm)
{

}*/

int 	main(int argc, char **argv)
{

	t_vm		*vm;

	vm = malloc(sizeof(vm));
	if (ft_check_error(argc, argv) == 0)
		return (0);
	ft_create_player(argv, vm);
//	ft_create_map(vm);


/*
 	ssize_t		ret;
	t_header	header;

	ret = read(0, &header, sizeof(t_header));
	if (ret == sizeof(t_header))
	{
		ft_printf("si c'est possible\n");
	}
	else
		ft_printf("non c'est pas possible\n");

//	nb magic code sur 4 octet pour lire en int il faut reverse
	swap_4(&header.magic);
	ft_printf("%x\n", header.magic);
	ft_printf("%s\n", header.prog_name);
//	nb code sur 4 octet a swap pour lire bon nombre
	swap_4(&header.prog_size);
	ft_printf("%u\n", header.prog_size);
	ft_printf("%s\n", header.comment);

	char *buffer_prog;

	buffer_prog = (char *)malloc(header.prog_size);

	read(0, buffer_prog, header.prog_size);

	unsigned int a;

	a = 0;
//	while (a < header.prog_size)
//	{
//		printf("%0.2hhx ", buffer_prog[a]);
//		a++;
//	}

	a = -1;
	ft_memset(vm.tab, 0, MEM_SIZE);
	ft_memcpy(vm.tab, buffer_prog, header.prog_size);

	int b;
	b = 1;
	while (++a < MEM_SIZE)
	{
		printf("%0.2hhx ", vm.tab[a]);
		if (b % 64 == 0)
			printf("\n");
		b++;
	}

	char *pt_head;

	pt_head = (char *)&header;
	a = 0;

//	printf("\n\n");
//
//	while (a < sizeof(header))
//	{
//		printf("%0.2hhx ", pt_head[a]);
//		a++;
//	}
 */
	return (0);
}


