/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:49:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/26 17:52:25 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	rs_loop(char *file, t_script *script)
{
	int		fd;
	char	*line;

	line = NULL;
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while (get_next_line(fd, &line) > 0)
	{
		ft_strappend(&script->buffer, line);
		ft_strappend(&script->buffer, "\n");
		ft_strdel(&line);
		script->size += ft_strlen(script->buffer);
	}
	close(fd);
	if (script->size > 0)
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
	script->size = 0;
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
	DG("{inv}{bol}{gre}read of script{eoc} script detected");
	return (1);
}
