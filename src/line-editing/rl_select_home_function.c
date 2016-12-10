/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_select_home_function.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 13:18:43 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 12:07:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_select_home_function(t_line *line, long int input)
{
	int	ret;

	if (!line->pos)
		return (0);
	if (RL_NOT(line->bitset, RL_SELECT))
		line->select = line->pos;
	ret = rl_home_function(line, input);
	RL_SET(line->bitset, RL_SELECT);
	rl_reset_display_post(line);
	return (ret);
}
