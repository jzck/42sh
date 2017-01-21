/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_word_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:47:31 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:39:44 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_wleft_function(t_line *line, long int input)
{
	size_t	len;

	if (!line->pos)
		return (0);
	len = rl_previous_word(line);
	curs_backward(&line->curs, len);
	line->pos -= len;
	return (0);
	(void)input;
}

int			rl_wright_function(t_line *line, long int input)
{
	size_t	len;

	if (line->pos == line->used)
		return (0);
	len = rl_next_word(line);
	curs_forward(&line->curs, len);
	line->pos += len;
	return (0);
	(void)input;
}

int			rl_select_wleft_function(t_line *line, long int input)
{
	int		ret;

	if (!line->pos)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_wleft_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}

int			rl_select_wright_function(t_line *line, long int input)
{
	int		ret;

	if (line->pos == line->used)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_wright_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}
