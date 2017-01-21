/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_page_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:39:57 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:37:41 by ariard           ###   ########.fr       */
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

int		rl_select_pagedown_function(t_line *line, long int input)
{
	int	ret;

	if (line->pos == line->used)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_pagedown_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}

int		rl_select_pageup_function(t_line *line, long int input)
{
	int	ret;

	if (!line->pos)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_pageup_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}
