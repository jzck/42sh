/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clipboard.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:04:33 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 15:57:47 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_clipboard_new_selected(t_line *line)
{
	int	start;
	int	size;

	RL_UNSET(line->bitset, RL_SELECT);
	start = (line->select > line->pos) ? line->pos : line->select;
	size = (line->select > line->pos ? line->select - line->pos : line->pos - line->select);
	if ((line->clipboard = ft_strsub(line->input, start, (size_t)size)) == NULL)
		return (-1);
	return (0);
}

int		rl_clipboard_new_selected_cut(t_line *line)
{
	int	start;
	int	size;

	RL_UNSET(line->bitset, RL_SELECT);
	start = (line->select > line->pos) ? line->pos : line->select;
	size = (line->select > line->pos ? line->select - line->pos : line->pos - line->select);
	if ((line->clipboard = ft_strsub(line->input, start, (size_t)size)) == NULL)
		return (-1);
	if (line->pos != start)
	{
		curs_backward(&line->curs, line->pos - start);
		line->pos = line->pos - (line->pos - start);
	}
	input_remove(line, -size);
	return (0);
}

int		rl_clipboard_new(t_line *line)
{
	int	start;
	int	real_pos;
	int	size;

	if (RL_IS(line->bitset, RL_SELECT))
		return (rl_clipboard_new_selected(line));
	size = line->curs.win_co;
	RL_UNSET(line->bitset, RL_SELECT);
	real_pos = line->pos + ft_strlen(line->prompt);
	start = (real_pos / line->curs.win_co) * line->curs.win_co;
	if (start)
		start -= ft_strlen(line->prompt);
	else
		size -= ft_strlen(line->prompt);
	if ((line->clipboard = ft_strsub(line->input, start, size)) == NULL)
		return (-1);
	return (0);
}

int		rl_clipboard_new_cut(t_line *line)
{
	int	start;
	int	real_pos;
	int	size;

	if (RL_IS(line->bitset, RL_SELECT))
		return (rl_clipboard_new_selected_cut(line));
	size = line->curs.win_co;
	RL_UNSET(line->bitset, RL_SELECT);
	real_pos = line->pos + ft_strlen(line->prompt);
	start = (real_pos / line->curs.win_co) * line->curs.win_co;
	if (start)
		start -= ft_strlen(line->prompt);
	else
		size -= ft_strlen(line->prompt);
	if ((line->clipboard = ft_strsub(line->input, start, size)) == NULL)
		return (-1);
	if (line->pos != start)
	{
		curs_backward(&line->curs, line->pos - start);
		line->pos = line->pos - (line->pos - start);
	}
	if (size > line->used - start)
		size = line->used - start;
	input_remove(line, -size);
	return (0);
}
