/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_sym.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:26:30 by ariard            #+#    #+#             */
/*   Updated: 2017/02/10 01:42:21 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_stackmatch	g_stackmatch[] =
{
	{EMPTY, CMD_NAME},
	{TK_GREAT, CMD_NAME},
	{CMD_NAME, TK_GREAT},
	{0, 0},
};

int			eval_sym(t_sym stack, t_sym new_sym)
{
	int				i;

	DG("eval head %s && sym %s", read_state(stack), read_state(new_sym));
	i = 0;
	while (g_stackmatch[i].top)
	{
		if (stack == g_stackmatch[i].under
			&& new_sym == g_stackmatch[i].top)
			return (0);
		i++;
	}
	return (1);
}
