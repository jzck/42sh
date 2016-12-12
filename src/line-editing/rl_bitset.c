/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_bitset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 10:31:34 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 13:26:06 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

static void			rl_toogle_esc(t_line *line, int set)
{
	static int			esc;

	if (!set)
		esc = RL_IS(line->bitset, RL_ESC);
	else if (set && esc)
	{
		RL_UNSET(line->bitset, RL_ESC);
		esc = 0;
	}
}

static void			rl_toogle_select(t_line *line, int set)
{
	static int			select;

	if (!set)
		select = RL_IS(line->bitset, RL_SELECT);
	else if (set &&\
			((select && RL_NOT(line->bitset, RL_SELECT)) ||\
			(!select && RL_IS(line->bitset, RL_SELECT))))
			rl_reset_display(line);
}

void				rl_toogle_bitset(t_line *line, int set)
{
	rl_toogle_esc(line, set);
	rl_toogle_select(line, set);
}

int				rl_finish(t_line *line)
{
	int			finish;
	int			stack;

	stack = RL_IS(line->bitset, RL_STACK);
	finish = RL_IS(line->bitset, RL_FINISH);
	if (!stack && !finish)
		return (0);
	rl_end_function(line, 0);
	write(1, "\n", 1);
	if (stack)
	{
		RL_UNSET(line->bitset, RL_STACK);
		if (rl_stack_line(line) < 0)
			return (-1);
	}
	if (finish)
		return (1);
	if (curs_coo_setup(&line->curs) < 0)
		return (-1);
	rl_set_prompt(line);
	rl_put_prompt(line);
	return (0);
}

