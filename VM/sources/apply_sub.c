/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_sub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:16:56 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/13 16:22:36 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

/*
** add : Opcode 4. Prend trois registres, additionne les 2 premiers, et met le r
** dans le troisième, juste avant de modifier le carry.
*/

void		apply_sub(t_process *process, t_env *env)
{
	uint32_t		reg[3];
	uint32_t		val;

	val = 0;
	reg[0] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE, T_REG);
	reg[1] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 1, T_REG);
	reg[2] = get_args(env->memory, process->pc + BYPASS_ARG_ENCODE + 2, T_REG);
	if (reg[0] > 0 && reg[0] <= 16 && reg[1] > 0 && reg[1] <= 16)
		val = process->reg[reg[0] - 1] - process->reg[reg[1] - 1];
	if (reg[2] > 0 && reg[2] <= 16)
		process->reg[reg[2] - 1] = val;
	process->carry = (val == 0);
	process->pc += BYPASS_ARG_ENCODE + 3;
	process->nb_cycle -= 10;
}
