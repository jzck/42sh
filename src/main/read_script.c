/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:49:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/24 18:50:55 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	rs_loop(char *file, t_script *script)
{
	int		fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &script->buffer) > 0)
	{
		ft_lsteadd(&script->queue,
			ft_lstnew(script->buffer, ft_strlen(script->buffer)));
		ft_strdel(&script->buffer);
		ft_lsteadd(&script->queue, ft_lstnew(ft_strdup("\n"), 1));
		script->q_size += 2;
	}
	close(fd);
	if (script->q_size > 0)
	{
		data_singleton()->opts &= ~SHELL_MODE_MASK;
		data_singleton()->opts |= SHELL_MODE_SCRIPT;
	}
	return (0);
}

static int	rs_setup(t_script *script)
{
	ft_bzero(script, sizeof(script));
	script->buffer = NULL;
	script->q_size = 0;
	script->queue = NULL; 
	return (0);
}

int			read_script(char *file)
{
	t_script	*script;

	script = &data_singleton()->script;
	if (!file)
		return (0);
	if (rs_setup(script) < 0)
		return (-1);
	if (rs_loop(file, script) < 0)
		return (-1);
	script->buffer = NULL;
	DG("{inv}{bol}{gre}read of script{eoc} script detected");
	return (1);
}
