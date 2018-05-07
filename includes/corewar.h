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
# define LEN_INIT_PROC    8
# define DUMP_LEN         64

# include <stdlib.h>
# include <unistd.h>
# include "op.h"

typedef unsigned char t_bool;

struct		s_input
{
	int				num_player[4];
	t_bool			db;
	t_bool			d;
	int				d_nb;
	t_bool			nc;
	unsigned char	*prog[4];
	t_header 		head[4];
	unsigned int	nb_p;
};

typedef struct		s_input t_input;

struct		s_cmd_save
{
	void			*cmd;
	unsigned char	params_type[3];
	unsigned char	params_size[3];
	int				params[3];
	unsigned int	cmd_len;
	int				cycle_wating;
	int				opcode;
};
typedef struct		s_cmd_save t_cmd_save;

struct 		s_player
{
	t_header		head;
	unsigned int	last_live;
	unsigned int	nb_live;
	unsigned int	id;
};
typedef struct		s_player t_player;

struct		s_proc
{
	unsigned int	PC;
	t_bool			carry;
	int				reg[REG_NUMBER];
	unsigned int	nb_live;
	t_cmd_save		cmd_save;
};
typedef struct		s_proc t_proc;

struct		s_vm
{
	t_bool			db;
	int				nb_p;
	t_bool			d;
	int				d_nb;
	unsigned char 	tab[MEM_SIZE];
	t_player 		player[4];
	t_proc			*process; // TODO test ref
	int				nb_process;
	int				len_process;
	int				cycle;
	int				cycle_to_die;
	int				cycle_last_check;
};
typedef struct s_vm t_vm;

typedef int (*t_cmd)(t_vm *vm, int ipr);
typedef int (*t_cal)(int a, int b);

struct		s_vm_proc
{
	t_vm	*vm;
	int		ipr;
	int		idx_mod;
	int		er;
};
typedef struct		s_vm_proc t_vm_proc;

/*
** ???
*/

int				input_cmdline(int argc, char **argv, t_input *input);
void			vm_init(t_vm *vm, t_input input);
void			vm_run(t_vm *vm);
int				vm_cycle(t_vm *vm, int *n);
void			vm_print(t_vm *vm);
int				stock_cmd(t_vm *vm, t_proc *processor, int op);
int 			ft_cmd_save_central_error(t_vm *vm, t_proc *processor, int op);
int 			ft_cmd_save_check_existence(int op, unsigned char tmp, int i);
int				ft_cmd_save_right_params(t_vm *vm, t_proc *processor, int op);
int 			ft_cmd_save_error_oct_params(t_vm *vm, t_proc *processor);
int				ft_analyze_oct_params(t_vm *vm, t_proc *processor, int op);
int				ft_cmd_save_add_len_params(t_vm *vm, t_proc *processor, int op);
unsigned char	ft_analyze_code(t_vm * vm, t_proc *processor, int left);
void			proc_exec(t_vm *vm, int ipr);
void			procs_exec(t_vm *vm);
signed char 	vm_read_1(t_vm *vm, unsigned int PC);
signed short 	vm_read_2(t_vm *vm, unsigned int PC);
signed int		vm_read_4(t_vm *vm, unsigned int PC);
void			reset_live(t_vm *vm);
int				check_nb_live_proc(t_vm *vm);
int				count_player_alive(t_vm *vm);
void			kill_proc(t_vm *vm);
void			vm_display_res(t_vm *vm);

/*
** UTILS
*/

int				ft_str_is_digit(char *str);
void			ft_usage(void);
void			input_free(t_input *input);
void			vm_free(t_vm *vm);
void			header_print(t_header head);
void			vm_dump_mem(t_vm *vm);
void			vm_write_1(t_vm *vm, unsigned int PC, unsigned char data);
void			vm_write_2(t_vm *vm, unsigned int PC, unsigned short data);
void			vm_write_4(t_vm *vm,unsigned int PC, unsigned int data);
int				read_param(t_vm_proc *vm_proc, int ipar);
void			load_param(t_vm_proc *vm_proc, int ipar, int data);
void			vm_fork(t_vm *vm, int ipr, int add);
unsigned int	cal_pc_add(unsigned int PC, int to_add);
void			init_vm_proc(t_vm_proc *vm_proc, t_vm *vm, int ipr, int idx_mod);
int				do_op(t_vm *vm, int ipr, t_cal cal);
void			vm_dump_mem_color(t_vm *vm);
void			debug(t_vm *vm);

/*
** CMD
*/

int				cmd_add(t_vm *vm, int ipr);
int				cmd_aff(t_vm *vm, int ipr);
int				cmd_and(t_vm *vm, int ipr);
int				cmd_fork(t_vm *vm, int ipr);
int				cmd_ld(t_vm *vm, int ipr);
int				cmd_ldi(t_vm *vm, int ipr);
int				cmd_lfork(t_vm *vm, int ipr);
int				cmd_live(t_vm *vm, int ipr);
int				cmd_lld(t_vm *vm, int ipr);
int				cmd_lldi(t_vm *vm, int ipr);
int				cmd_or(t_vm *vm, int ipr);
int				cmd_st(t_vm *vm, int ipr);
int				cmd_sti(t_vm *vm, int ipr);
int				cmd_sub(t_vm *vm, int ipr);
int				cmd_xor(t_vm *vm, int ipr);
int				cmd_zjmp(t_vm *vm, int ipr);

#endif
