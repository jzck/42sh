/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_dquote_function.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:46:36 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 02:20:10 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_dquote_function(t_line *line, long int input)
{
	if (!RL_IS(line->bitset, RL_ESC))
	{
		if (RL_IS(line->bitset, RL_DQUOTE))
			RL_UNSET(line->bitset, RL_DQUOTE);
		else
			RL_SET(line->bitset, RL_DQUOTE);
	}
	return (rl_default_function(line, input));
}
