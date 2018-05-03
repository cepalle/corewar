/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   op.h                                             .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: cepalle <cepalle@student.le-101.fr>        +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/09 16:56:27 by cepalle      #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 09:52:27 by cepalle     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef COREWAR_H
# define COREWAR_H

# define REG_CONTENT_SIZE 4
# define LEN_INIT_PROC 8

# include <stdlib.h>
# include <unistd.h>
# include "op.h"

struct		s_input
{
	unsigned char	n;
	unsigned char	*prog[4];
	unsigned int	nb_p;
	unsigned char	d;
	unsigned int	d_nb;
	t_header 		head[4];
};
typedef struct		s_input t_input;

struct		s_cmd_save
{
	void			*cmd;
	unsigned char	params_type[3];
	unsigned char	params_size[3];
	unsigned int	params[3];
	unsigned int	cmd_len;
	unsigned int	cycle_wating;
};
typedef struct		s_cmd_save t_cmd_save;

struct 		s_player
{
	t_header		head;
	unsigned int	last_live;
	unsigned int	live; // rename nb_live
	unsigned int	is_alive; // init 1
	unsigned int	id;
};
typedef struct		s_player t_player;

struct		s_proc
{
	unsigned int	PC;
	unsigned char	carry;
	unsigned int	reg[REG_NUMBER];
	t_cmd_save		cmd_save;
};
typedef struct		s_proc t_proc;

struct		s_vm
{
	unsigned int	nb_p;
	unsigned char	d;
	unsigned char 	tab[MEM_SIZE];
	t_player 		player[4];
	t_proc			*process; // TODO test ref
	unsigned int 	nb_process;
	unsigned int 	len_process;
	unsigned int 	cycle;
};
typedef struct s_vm t_vm;

typedef void (*t_cmd)(t_vm *vm, t_proc *proc);

/*
** ???
*/

int			input_cmdline(int argc, char **argv, t_input *input);
void		vm_init(t_vm *vm, t_input input);
void		vm_run(t_vm *vm);
void		vm_cycle(t_vm *vm);
void		vm_print(t_vm *vm);
int 		stock_cmd(t_vm *vm, t_proc *processor);
void		proc_exec(t_vm *vm, t_proc *proc);

/*
** UTILS
*/

int			ft_str_is_digit(char *str);
void		ft_usage(void);
void		input_free(t_input *input);
void		vm_free(t_vm *vm);
void		header_print(t_header head);
void		vm_dump_mem(t_vm *vm);
void		vm_write_1(t_vm *vm, unsigned int PC, unsigned char data);
void		vm_write_2(t_vm *vm, unsigned int PC, unsigned short data);
void		vm_write_4(t_vm *vm,unsigned int PC, unsigned int data);

/*
** CMD
*/

int		cmd_add(t_vm *vm, t_proc *proc);
int		cmd_aff(t_vm *vm, t_proc *proc);
int		cmd_and(t_vm *vm, t_proc *proc);
int		cmd_fork(t_vm *vm, t_proc *proc);
int		cmd_ld(t_vm *vm, t_proc *proc);
int		cmd_ldi(t_vm *vm, t_proc *proc);
int		cmd_lfork(t_vm *vm, t_proc *proc);
int		cmd_live(t_vm *vm, t_proc *proc);
int		cmd_lld(t_vm *vm, t_proc *proc);
int		cmd_lldi(t_vm *vm, t_proc *proc);
int		cmd_or(t_vm *vm, t_proc *proc);
int		cmd_st(t_vm *vm, t_proc *proc);
int		cmd_sti(t_vm *vm, t_proc *proc);
int		cmd_sub(t_vm *vm, t_proc *proc);
int		cmd_xor(t_vm *vm, t_proc *proc);
int		cmd_zjmp(t_vm *vm, t_proc *proc);

#endif
