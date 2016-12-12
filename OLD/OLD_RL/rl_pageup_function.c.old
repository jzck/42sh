/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_pageup_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:32:16 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:04:07 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_pageup_function(t_line *line, long int input)
{
	int		len;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (!line->pos)
		return (0);
	len = (line->curs.win_co > line->pos ? line->pos : line->curs.win_co);
	curs_backward(&line->curs, len);
	line->pos -= len;
	return (0);
	(void)input;
}
