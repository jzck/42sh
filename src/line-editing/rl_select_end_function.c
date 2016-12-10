/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_select_end_function.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:19:35 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 12:07:40 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_select_end_function(t_line *line, long int input)
{
	int	ret;

	if (line->pos == line->used)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_end_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_ante(line);
	return (ret);
}
