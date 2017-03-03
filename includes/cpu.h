/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpu.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 14:52:48 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/03 15:00:52 by aiwanesk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPU_H
# define CPU_H

# include "../libs/libft/include/libft.h"
# include "op.h"

# include <stdint.h>
# include <stdbool.h>

# define PCANDARG (process->pc + 2)
# define CGREEN "\033[32m"
# define CRED "\033[31m"
# define CWHITE  "\033[37m"

typedef struct s_data		t_data;
typedef struct s_arg		t_arg;
typedef struct s_fork		t_fork;

struct s_dict g_tab[2];

struct				s_fork
{
	bool		isfork;
	uint32_t	pc;
};

typedef struct		s_process
{
	uint32_t		reg[16];
	uint32_t		pc;
	uint32_t		id;
	uint32_t		alive;
	unsigned char	carry;
	char			*name;
	uint32_t		nb_cycle;
	unsigned char	memory[MEM_SIZE];
	bool			isdead;
	t_fork			fork;
}					t_process;

struct				s_data
{
	char val[9];
};

struct				s_arg
{
	int total_to_read[4];
};

t_arg				parsing_request(t_process *p,
		unsigned char memory[MEM_SIZE]);

struct s_data		get_data_from_hex(int val);
int					int_to_bin(unsigned int k);

void				exit_error(char *s);

t_process			cpu(t_process p);

void				apply_function(t_process *process);

void				apply_and(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_or(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_xor(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_add(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_sub(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_ld(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_st(t_process *process, t_arg arg);

void				apply_aff(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_fork(t_process *process, t_arg arg);
void				apply_lfork(t_process *process, t_arg arg);

void				apply_ldi(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_sti(t_process *process, t_arg arg);
void				apply_lld(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);
void				apply_lldi(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

void				apply_live(t_process *process,
		unsigned char memory[MEM_SIZE]);
void				apply_zjmp(t_process *process,
		unsigned char memory[MEM_SIZE], t_arg arg);

int					int_to_read(char *t, int i, int op);

#endif
