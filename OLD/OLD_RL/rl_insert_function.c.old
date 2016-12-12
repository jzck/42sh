/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_insert_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:28:01 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 18:29:33 by sbenning         ###   ########.fr       */
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
