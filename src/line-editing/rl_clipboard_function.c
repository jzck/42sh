/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_clipboard_function.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:32:11 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:36:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_copy_function(t_line *line, long int input)
{
	if (line->clipboard)
		ft_memdel((void **)&line->clipboard);
	if (rl_clipboard_new(line) < 0)
		return (-1);
	return (0);
	(void)input;
}

int			rl_cut_function(t_line *line, long int input)
{
	if (line->clipboard)
		ft_memdel((void **)&line->clipboard);
	if (rl_clipboard_new_cut(line) < 0)
		return (-1);
	rl_reset_display_post(line);
	return (0);
	(void)input;
}

int			rl_paste_function(t_line *line, long int input)
{
	int		len;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	if (!line->clipboard)
		return (0);
	len = ft_strlen(line->clipboard);
	if (!len)
		return (0);
	if (RL_IS(line->bitset, RL_INSERT))
	{
		if (input_move(line, line->clipboard, len) < 0)
			return (-1);
	}
	else
	{
		if (input_maj(line, line->clipboard, len) < 0)
			return (-1);
	}
	rl_reset_display_post(line);
	curs_forward(&line->curs, len);
	line->pos += len;
	return (0);
	(void)input;
}
