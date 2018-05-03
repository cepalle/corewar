/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   check_error.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 17:07:37 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 17:07:38 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include <fcntl.h>
#include <unistd.h>
#include "corewar.h"

static	void	ft_fill_player(t_input *input, int fd)
{
	ssize_t	ret;

	ret = read(fd, &input->head[input->nb_p], sizeof(t_header));
	if (ret != sizeof(t_header))
		ft_printf("Error read\n");
	swap_4(&input->head[input->nb_p].magic);
	swap_4(&input->head[input->nb_p].prog_size);
	input->prog[input->nb_p] = ft_memalloc(sizeof(char) *
							input->head[input->nb_p].prog_size);
	ret = read(fd, input->prog[input->nb_p],
		input->head[input->nb_p].prog_size);
	if (ret != sizeof(input->head[input->nb_p].prog_size))
		ft_printf("Error read\n");
}

static	int		ft_check_player(char *argv, t_input *input)
{
	int		fd;
	size_t	len;

	if (input->nb_p >= MAX_PLAYERS)
	{
		ft_printf("too many player\n");
		return (0);
	}
	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp(argv + (len - 4), ".cor", 4) != 0)))
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Unreachable file\n");
		return (0);
	}
	ft_fill_player(input, fd);
	input->nb_p = input->nb_p + 1;
	close(fd);
	return (1);
}


/*static	int 	ft_check_champ_nb(char **argv, t_input *input, int *a, int argc)
{


}*/

static	int		ft_check_option(char **argv, t_input *input, int *a, int argc)
{
//	if (ft_strcmp(argv[*a], "-n"))
//		if (ft_check_champ_nb(argv, input, a, argc) == 0)
//			return (1);
	if (ft_strcmp(argv[*a], "-d") == 0)
	{
		ft_printf("-d option enable\n");
		input->d = 1;
		input->d_nb = 0;
		if (*a + 1 < argc)
		{
			*a = *a + 1;
			input->d_nb = ft_atoi(argv[*a]);
			if (input->d_nb < 0)
				input->d = 0;
		}
		ft_printf("nb_d option = %d, d = %d\n", input->d_nb, input->d);
		return (1);
	}
	if (ft_strcmp(argv[*a], "-nc") == 0)
	{
		input->nc = 1;
		ft_printf("Ncurses output mode\n");
		return (1);
	}
	return (0);
}

static	int		ft_check_arg(char **argv, t_input *input, int argc)
{
	int a;

	a = 1;
	while (argv[a])
	{
		if (ft_check_option(argv, input, &a, argc) == 0
			&& ft_check_player(argv[a], input) == 0)
		{
			ft_printf("Can't read source file %s\n", argv[a]);
			return (0);
		}
		a++;
	}
	return (1);
}

int				input_cmdline(int argc, char **argv, t_input *input)
{
	int a;

	a = -1;
	input->nb_p = 0;
	input->d = 0;
	input->d_nb = 0;
	while (++a < MAX_PLAYERS)
		input->num_player[a] = -1;
	if (argc == 1)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_arg(argv, input, argc) == 0)
		return (0);
	return (1);
}
