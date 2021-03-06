/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_live.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aiwanesk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:09:42 by aiwanesk          #+#    #+#             */
/*   Updated: 2017/03/09 14:06:16 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cpu.h"

void				apply_live(t_process *process, t_env *env)
{
	uint32_t		tmp;
	int16_t			total;
	uint32_t		length;

	tmp = 0;
	length = length_label(env->memory[process->pc]);
	total = (int16_t)get_args(env->memory, process->pc + 1, length);
	while (tmp < env->nbprocess)
	{
		if (env->process[tmp].id == (uint32_t)total)
			++env->process[tmp].alive;
		++tmp;
	}
	process->pc += (length + 1);
	process->nb_cycle -= 10;
	protocol_lc(*env);
}

