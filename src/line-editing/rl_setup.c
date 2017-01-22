/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rl_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 18:07:47 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/22 21:25:10 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_readline.h"

int		rl_setup(t_line *line)
{
	if (SHELL_HAS_JOBC(data_singleton()->opts))
		do_job_notification();
	data_singleton()->opts &= ~SHELL_MODE_MASK;
	data_singleton()->opts |= SHELL_MODE_INPUT;
	ft_bzero(line, sizeof(t_line));
	if (curs_setup(&line->curs) < 0)
		return (-1);
	RL_SET(line->bitset, RL_INSERT);
	rl_set_prompt(line);
	return (0);
}

int		rl_cleanup(t_line *line)
{
	data_singleton()->opts &= ~SHELL_MODE_MASK;
	data_singleton()->opts |= SHELL_MODE_EXEC;
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
