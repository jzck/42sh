/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_display.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:38:39 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:37:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

void		rl_reset_display_post(t_line *line)
{
	size_t	len;

	len = ft_strlen(line->input + line->pos);
	curs_clear_post(&line->curs);
	if (len == 0)
		return ;
	if (RL_NOT(line->bitset, RL_SELECT) || (RL_IS(line->bitset, RL_SELECT) && line->select < line->pos))
	{
		curs_write_static(&line->curs, line->input + line->pos, len);
		return;
	}
	if (line->select == line->used)
	{
		curs_video_write_static(&line->curs, line->input + line->pos, len);
		return ;
	}
	curs_video_write(&line->curs, line->input + line->pos, line->select - line->pos);
	curs_write(&line->curs, line->input + line->select, line->used - line->select);
	curs_backward(&line->curs, line->used - line->pos);
}

void		rl_reset_display_ante(t_line *line)
{
	if (!line->pos)
		return ;
	curs_backward(&line->curs, line->pos);
	if (RL_NOT(line->bitset, RL_SELECT) || (RL_IS(line->bitset, RL_SELECT) && line->select > line->pos))
	{
		curs_write(&line->curs, line->input, line->pos);
		return ;
	}
	if (line->select == 0)
	{
		curs_video_write(&line->curs, line->input, line->pos);
		return ;
	}
	curs_write(&line->curs, line->input, line->select);
	curs_video_write(&line->curs, line->input + line->select, line->pos - line->select);
}

void		rl_reset_display(t_line *line)
{
	rl_reset_display_ante(line);
	rl_reset_display_post(line);
}
