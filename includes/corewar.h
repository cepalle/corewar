/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:27:57 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */


#ifndef COREWAR_H
# define COREWAR_H

# define REG_CONTENT_SIZE 4
#include <stdlib.h>
#include <unistd.h>
#include "op.h"

typedef	struct		s_proc
{
	int				PC;
	int				carry;
	int 			reg[REG_NUMBER];
}					t_proc;

typedef	struct 		s_player
{
	t_header		head;
	unsigned int	last_live;
	unsigned int	live;
	t_proc			*PC;
	char			*prog;
}					t_player;

typedef	struct 		s_vm
{
	unsigned char 	tab[MEM_SIZE];
	int 			nb_p;
	t_player 		*player;
	unsigned int 	nb_process;
	unsigned int 	cycle;
}					t_vm;

int					ft_check_error(int argc, char **argv);
void				ft_usage(void);
int					ft_count_player(char ** argv);
void				ft_create_map(t_vm *vm);
void				ft_create_player(char **argv, t_vm *vm);

#endif
