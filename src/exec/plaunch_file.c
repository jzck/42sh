/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 14:53:31 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 20:22:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void		error_launch(char *error_ori, char *error_type, int error_code)
{
	ft_dprintf(2, "{red}%s: %s%s{eoc}\n", SHELL_NAME, error_ori, error_type);
	exit(error_code);
}

int				plaunch_file(t_process *p)
{
	if (!p->data.cmd.path)
		error_launch("command not found: ", p->data.cmd.av[0], 127);
	else if (!p->data.cmd.stat)
		error_launch(p->data.cmd.av[0], ": no such file or directory", 127);
	else if (S_ISDIR(p->data.cmd.stat->st_mode))
		error_launch(p->data.cmd.av[0], ": is a directory", 126);
	else if (access(p->data.cmd.path, X_OK) == -1)
		error_launch("permission denied: ", p->data.cmd.av[0], 126);
	(*p->data.cmd.execf)(
			p->data.cmd.path,
			p->data.cmd.av,
			data_singleton()->env);
	error_launch("internal execve error on ", p->data.cmd.av[0], 42);
	return (0);
}
