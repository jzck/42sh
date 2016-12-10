/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_quote_function.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:45:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 12:05:26 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

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
