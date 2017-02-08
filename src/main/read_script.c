/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:49:31 by ariard            #+#    #+#             */
/*   Updated: 2017/02/06 22:05:31 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			get_script_content(t_script *script)
{
	char	*line;

	line = NULL;
	while (((get_next_line(script->fd, &line))) > 0)
	{
		ft_strappend(&script->buffer, line);
		ft_strappend(&script->buffer, "\n");
		ft_strdel(&line);
		script->size += ft_strlen(script->buffer);
	}
	if (script->size)
		script->buffer[ft_strlen(script->buffer) - 1] = 0;
	return (script->size);
}
	
static int	rs_read(char *file, t_script *script)
{
	if ((script->fd = open(file, O_RDONLY)) == -1)
		return (0);
	get_script_content(script);
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
	script->fd = -1;
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
	if (rs_read(file, script) < 0)
		return (-1);
	DG("{inv}{bol}{gre}read of script{eoc} script detected");
	return (1);
}
