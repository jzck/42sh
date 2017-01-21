/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_long_move_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:55:48 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:34:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_home_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (!line->pos)
		return (0);
	curs_backward(&line->curs, line->pos);
	line->pos = 0;
	return (0);
	(void)input;
}

int			rl_end_function(t_line *line, long int input)
{
	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (line->pos == line->used)
		return (0);
	curs_forward(&line->curs, line->used - line->pos);
	line->pos = line->used;
	return (0);
	(void)input;
}

int			rl_select_home_function(t_line *line, long int input)
{
	int		ret;

	if (!line->pos)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_home_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}

int			rl_select_end_function(t_line *line, long int input)
{
	int		ret;

	if (line->pos == line->used)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_end_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}
