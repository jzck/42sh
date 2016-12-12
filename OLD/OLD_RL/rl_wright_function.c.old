/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_right_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 19:20:15 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 12:03:54 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static int	rl_next_word(t_line *line)
{
	int		i;
	int		flag;

	if (RL_IS(line->bitset, RL_SELECT))
		RL_UNSET(line->bitset, RL_SELECT);
	i = line->pos;
	flag = 0;
	while (line->input[i] && (line->input[i] == ' ' || !flag))
	{
		if (line->input[i] == ' ')
			flag = 1;
		i++;
	}
	return (i - line->pos);
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
