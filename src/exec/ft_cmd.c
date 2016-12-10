/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/10 17:34:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

extern pid_t	g_pid;

int		ft_cmd_process(char **argv, t_data *data)
{
	char	*execpath;

	ft_expand_dollar(argv, data->env);
	if (ft_builtin(argv, data))
		return (0);
	else if (ft_strchr(argv[0], '/'))
		execpath = ft_strdup(argv[0]);
	else if (!(execpath = ft_findexec(ft_getenv(data->env, "PATH"), argv[0])))
	{
		ft_dprintf(2, "%s: command not found: %s\n", SHELL_NAME, argv[0]);
		set_exitstatus(data, 127);
		return (-1);
	}
	return (ft_cmd_exec(execpath, argv, data));
}

int		ft_cmd_exec(char *execpath, char **argv, t_data *data)
{
	pid_t	pid;
	int		status;

	if (access(execpath, X_OK) == -1)
	{
		ft_dprintf(2, "%s: permission denied: %s\n", SHELL_NAME, argv[0]);
		ft_strdel(&execpath);
		return (-1);
	}
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid == 0)
	{
		fd_redirect(data);
		execve(execpath, argv, data->env);
	}
	else
	{
		ft_strdel(&execpath);
		g_pid = pid;
		if (data->exec.amp)
			job_new(data, argv, pid);
		else if (data->exec.fdout == STDOUT)
		{
			waitpid(pid, &status, 0);
			set_exitstatus(data, status);
		}
		g_pid = 0;
	}
	return (0);
}
