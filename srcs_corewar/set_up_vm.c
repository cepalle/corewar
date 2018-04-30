/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   set_up_vm.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: aurollan <aurollan@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/29 17:11:45 by aurollan     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/29 17:11:46 by aurollan    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "op.h"
#include "corewar.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int				ft_count_player(char **argv)
{
	int		a;
	size_t	len;
	int		count;

	ft_printf("ft_count_player\n");
	a = 1;
	count = 0;
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ft_strncmp(argv[a] + (len - 4), ".cor", 4) == 0)
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

static	void	ft_fill_player(char *argv, t_vm *vm, int num_player)
{
	int		a;
	int		fd;
	ssize_t	ret;

	ft_printf("ft_fill_player\n");
	fd = open(argv, O_RDONLY);
	if (fd == -1)
		ft_printf("erreur ouverture fd\n");
	ret = read(fd, &vm->player[num_player].head, sizeof(t_header));
	swap_4(&(vm->player[num_player].head.magic));
	swap_4(&(vm->player[num_player].head.prog_size));
	if (ret == sizeof(t_header))
		ft_printf("j'ai cree le header du joueur\n");
	vm->player[num_player].prog = ft_memalloc(sizeof(char) *
									vm->player[num_player].head.prog_size);
	ret = read(fd, vm->player[num_player].prog,
		vm->player[num_player].head.prog_size);
	close(fd);
}

void			ft_create_player(char **argv, t_vm *vm)
{
	int		a;
	int		num_player;
	size_t	len;

	a = 1;
	num_player = 0;
	vm->nb_p = ft_count_player(argv);
	vm->player = ft_memalloc(sizeof(t_player) * vm->nb_p);
	while (argv[a])
	{
		len = ft_strlen(argv[a]);
		if (len > 4 && ft_strncmp(argv[a] + (len - 4), ".cor", 4) == 0)
		{
			ft_printf("je vais travailler sur le joueur %s\n", argv[a]);
			ft_fill_player(argv[a], vm, num_player);
			num_player++;
		}
		a++;
	}
}

void			ft_create_map(t_vm *vm)
{
	int a;
	int res;
	int placement;

	a = 0;
	res = 0;
	placement = MEM_SIZE / vm->nb_p;
	ft_printf("placement = %d\n", placement);
	ft_memset(vm->tab, 0, MEM_SIZE);
	while (a < vm->nb_p)
	{
		ft_memcpy(vm->tab + res, vm->player[a].prog,
				vm->player[a].head.prog_size);
		res = res + placement;
		a++;
	}
}
