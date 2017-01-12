/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quoting_function.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 12:35:25 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 12:36:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_esc_function(t_line *line, long int input)
{
	if (RL_NOT(line->bitset, RL_ESC))
		RL_SET(line->bitset, RL_ESC);
	return (rl_default_function(line, input));
}

int		rl_quote_function(t_line *line, long int input)
{
	if (RL_NOT(line->bitset, RL_ESC))
	{
		if (RL_IS(line->bitset, RL_QUOTE))
			RL_UNSET(line->bitset, RL_QUOTE);
		else
			RL_SET(line->bitset, RL_QUOTE);
	}
	return (rl_default_function(line, input));
}

int		rl_dquote_function(t_line *line, long int input)
{
	if (RL_NOT(line->bitset, RL_ESC))
	{
		if (RL_IS(line->bitset, RL_DQUOTE))
			RL_UNSET(line->bitset, RL_DQUOTE);
		else
			RL_SET(line->bitset, RL_DQUOTE);
	}
	return (rl_default_function(line, input));
}
