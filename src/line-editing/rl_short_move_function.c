/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_move_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:53:18 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 12:54:52 by sbenning         ###   ########.fr       */
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

int			rl_right_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (line->pos == line->used)
		return (0);
	curs_forward(&line->curs, 1);
	line->pos += 1;
	return (0);
	(void)input;
}

int			rl_select_left_function(t_line *line, long int input)
{
	int		ret;

	if (!line->pos)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_left_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}

int			rl_select_right_function(t_line *line, long int input)
{
	int		ret;

	if (line->pos == line->used)
		return (0);
	if (!RL_IS(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_right_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}
