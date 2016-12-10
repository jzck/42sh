/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_paste_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:40:45 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 18:22:38 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

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
