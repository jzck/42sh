/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_pagedown_function.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:32:26 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:04:19 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_pagedown_function(t_line *line, long int input)
{
	int		len;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (line->pos == line->used)
		return (0);
	len = line->used - line->pos;
	len = (line->curs.win_co > len ? len : line->curs.win_co);
	curs_forward(&line->curs, len);
	line->pos += len;
	return (0);
	(void)input;
}

