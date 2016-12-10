/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_esc_function.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 00:40:22 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/10 12:05:51 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_esc_function(t_line *line, long int input)
{
	if (RL_NOT(line->bitset, RL_ESC))
		RL_SET(line->bitset, RL_ESC);
	return (rl_default_function(line, input));
}
