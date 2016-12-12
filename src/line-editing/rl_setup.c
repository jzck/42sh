/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:07:47 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/12 12:20:55 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_setup(t_line *line)
{
	ft_bzero(line, sizeof(t_line));
	if (curs_setup(&line->curs) < 0)
		return (-1);
	RL_SET(line->bitset, RL_INSERT);
	line->prompt = "$> ";
	rl_set_prompt(line);
	return (0);
}

int		rl_cleanup(t_line *line)
{
	if (curs_cleanup(&line->curs) < 0)
		return (-1);
	if (rl_merge_line(line) < 0)
		return (-1);
	return (0);
}

void	rl_teardown(t_line *line)
{
	rl_cleanup(line);
	if (line->input)
		ft_memdel((void **)&line->input);
	line->pos = 0;
}
