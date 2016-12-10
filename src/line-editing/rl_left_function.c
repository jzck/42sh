/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_left_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:17:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:37:48 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_left_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (!line->pos)
		return (0);
	curs_backward(&line->curs, 1);
	line->pos -= 1;
	return (0);
	(void)input;
}
