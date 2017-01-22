/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:49:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 23:11:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	rs_loop(char *file, t_script *script)
{
	int		fd;

	script->queue = ft_memalloc(sizeof(t_list));
	fd = open(file, O_RDONLY);
	while (get_next_line(fd, &script->buffer) > 0)
	{
		ft_lsteadd(&script->queue,
			ft_lstnew(script->buffer, ft_strlen(script->buffer)));
		ft_strdel(&script->buffer);
	}
	close(fd);
	return (0);
}

static int	rs_setup(t_script *script)
{
	ft_bzero(script, sizeof(script));
	script->buffer = NULL;
	script->b_size = 0;
	script->q_size = 0;
	return (0);
}

int			ft_read_script(char *file)
{
	t_script	*script;

	script = &data_singleton()->script;
	if (!file)
		return (0);
	if (rs_setup(script) < 0)
		return (-1);
	if (rs_loop(file, script) < 0)
		return (-1);
	if (rs_shebang_check(file, script) < 0)
		return (-1);
	script->buffer = NULL;
	DG("{inv}{bol}{gre}read of script{eoc} script detected");
	return (1);
}
