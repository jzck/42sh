/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_word_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:48:07 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:39:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int			rl_previous_word(t_line *line)
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

int			rl_next_word(t_line *line)
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

