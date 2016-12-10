/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_nl_function.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:03:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 12:06:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_nl_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (RL_NOT(line->bitset, RL_QUOTING))
		RL_SET(line->bitset, RL_FINISH);
	RL_SET(line->bitset, RL_STACK);
	return (0);
	(void)input;
}
