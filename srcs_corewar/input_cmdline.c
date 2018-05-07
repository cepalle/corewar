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

static	int		ft_fill_player(t_input *input, int fd)
{
	ssize_t	ret;

	ret = read(fd, &input->head[input->nb_p], sizeof(t_header));
	if (ret != sizeof(t_header))
	{
		ft_printf("Error read header\n");
		return (0);
	}
	swap_4(&input->head[input->nb_p].magic);
	swap_4(&input->head[input->nb_p].prog_size);
	input->prog[input->nb_p] = ft_memalloc(sizeof(char) *
							input->head[input->nb_p].prog_size + 1);
	ret = read(fd, input->prog[input->nb_p],
		input->head[input->nb_p].prog_size + 1);
	if (ret != input->head[input->nb_p].prog_size)
	{
		ft_printf("Error read prog\n");
		return (0);
	}
	return (1);
}

static	int		ft_check_player(char *argv, t_input *input)
{
	int		fd;
	size_t	len;

	len = ft_strlen(argv);
	if (len > 4 && ((ft_strncmp(argv + (len - 4), ".cor", 4) != 0)))
		return (0);
	fd = open(argv, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Can't read source file %s\n", argv);
		return (0);
	}
	if (input->nb_p >= MAX_PLAYERS)
	{
		ft_printf("Too many player\n");
		return (0);
	}
	if (!ft_fill_player(input, fd))
		return (0);
	input->nb_p = input->nb_p + 1;
	close(fd);
	return (1);
}

static	int		ft_check_champ_num(char **argv, t_input *input,
									int *a, int argc)
{
	if (*a + 1 < argc)
	{
		*a = *a + 1;
		if (input->num_player[input->nb_p] == 0)
		{
			if (ft_atoi(argv[*a]) < 0)
			{
				ft_printf("Negatif number not allowed\n");
				return (0);
			}
			input->num_player[input->nb_p] = ft_atoi(argv[*a]);
		}
	}
	else
	{
		ft_printf("No champion anymore\n");
		return (0);
	}
	if (*a + 1 == argc)
	{
		ft_printf("No champion anymore\n");
		return (0);
	}
	return (1);
}

static	int		ft_check_dump(char **argv, t_input *input, int *a, int argc)
{
	if (ft_strcmp(argv[*a], "-d") == 0)
	{
		input->d = 1;
		input->d_nb = 0;
		if (*a + 1 < argc)
		{
			*a = *a + 1;
			input->d_nb = ft_atoi(argv[*a]);
			if (input->d_nb < 0)
				input->d = 0;
		}
		else
			return (0);
		return (1);
	}
	return (0);
}

static	int		ft_check_option(char **argv, t_input *input, int *a, int argc)
{
	if (ft_strcmp(argv[*a], "-n") == 0)
	{
		if (ft_check_champ_num(argv, input, a, argc) == 1)
			return (1);
		else
			return (0);
	}
	if (ft_check_dump(argv, input, a, argc) == 1)
		return (1);
	if (ft_strcmp(argv[*a], "-nc") == 0)
	{
		input->nc = 1;
		return (1);
	}
	if (ft_strcmp(argv[*a], "-db") == 0)
	{
		input->db = 1;
		return (1);
	}
	return (0);
}

static	int		ft_check_arg(char **argv, t_input *input, int argc)
{
	int		a;
	size_t	len;

	a = 1;
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ((ft_strncmp(argv[a] + (len - 4), ".cor", 4) == 0)))
		{
			if (ft_check_player(argv[a], input) == 0)
				return (0);
		}
		else if (ft_check_option(argv, input, &a, argc) == 0)
			return (0);
		if (a < argc)
			a++;
	}
	return (1);
}

static	int		ft_check_double_num(t_input *input)
{
	unsigned int a;
	unsigned int b;

	a = 0;
	while (a < input->nb_p)
	{
		b = a + 1;
		while (b < input->nb_p)
		{
			if (input->num_player[a] == input->num_player[b]
				&& input->num_player[a] != 0)
			{
				ft_printf("Error same champion number\n");
				return (0);
			}
			b++;
		}
		a++;
	}
	return (1);
}

static	int		player_check_header(t_input *input)
{
	unsigned int a;

	a = 0;
	while (a < input->nb_p)
	{
		if (input->head[a].prog_size > CHAMP_MAX_SIZE ||
			input->head[a].prog_size == 0)
			return (0);
		if (ft_strlen(input->head[a].prog_name) == 0 ||
			ft_strlen(input->head[a].prog_name) > PROG_NAME_LENGTH)
			return (0);
		if (input->head[a].magic != COREWAR_EXEC_MAGIC)
			return (0);
		if (ft_strlen(input->head[a].comment) > COMMENT_LENGTH)
			return (0);
		a++;
	}
	return (1);
}

static	int		ft_check_n_option(t_input *input)
{
	int a;

	a = -1;
	while (++a < 3)
	{
		if (input->num_player[a] != 0 &&
			ft_check_double_num(input) == 0)
		{
			ft_printf("Error champion number\n");
			return (0);
		}
	}
	return (1);
}

int				input_cmdline(int argc, char **argv, t_input *input)
{
	int a;

	a = -1;
	input->nb_p = 0;
	input->db = 0;
	input->d = 0;
	input->d_nb = 0;
	while (++a < MAX_PLAYERS)
		input->num_player[a] = 0;
	if (argc == 1 || ft_check_arg(argv, input, argc) == 0)
	{
		ft_usage();
		return (0);
	}
	if (ft_check_n_option(input) == 0)
		return (0);
	if (player_check_header(input) == 0)
	{
		ft_printf("Error player header\n");
		return (0);
	}
	return (1);
}
