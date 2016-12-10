/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_left_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:17:13 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:03:42 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	rl_previous_word(t_line *line)
{
	int		i;
	int		len;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	i = 0;
	while (line->input[i] && i < line->pos)
	{
		if (!i && line->input[i] != ' ')
			len = i;
		if (i && line->input[i - 1] == ' ' && line->input[i] != ' ')
			len = i;
		i++;
	}
	return (line->pos - len);
}

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
