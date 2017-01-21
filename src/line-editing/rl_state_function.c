/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_state_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 13:00:59 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:39:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_insert_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_INSERT))
		RL_UNSET(line->bitset, RL_INSERT);
	else
		RL_SET(line->bitset, RL_INSERT);
	return (0);
	(void)input;
}

int		rl_nl_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	RL_SET(line->bitset, RL_STACK);
	if (RL_NOT(line->bitset, RL_QUOTING))
		RL_SET(line->bitset, RL_FINISH);
	return (0);
	(void)input;
}
