/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/27 21:13:18 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 18:32:49 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
extern pid_t	g_pid;

int		ft_cmd_process(char **argv, t_data *data)
{
	char	**path;
	char	*execpath;

	path = ft_strsplit(ft_getenv(data->env, "PATH"), ':');
	ft_expand_dollar(argv, data->env);
	if (ft_builtin(argv, data))
		return (0);
	else if (ft_strchr(argv[0], '/'))
		execpath = argv[0];
	else if (!(execpath = ft_findexec(path, argv[0])))
	{
		ft_dprintf(2, "minishell: command not found: %s\n", argv[0]);
		return (-1);
	}
	return (ft_cmd_exec(execpath, argv, data));
}

int		ft_cmd_exec(char *execpath, char **argv, t_data *data)
{
	pid_t	pid;
	int		status;
	char	**environ;

	if (access(execpath, X_OK) == -1)
	{
		ft_dprintf(2, "minishell: permission denied: %s\n", argv[0]);
		return (-1);
	}
	ft_dprintf(2, "gonna fork, in=%i, out=%i\n", data->fdin, data->fdout);
	if ((pid = fork()) == -1)
		return (-1);
	else if (pid == 0)
	{
		if (data->fdin != STDIN)
		{
			dup2(data->fdin, STDIN);
			close(data->fdin);
		}
		if (data->fdout != STDOUT)
		{
			dup2(data->fdout, STDOUT);
			close(data->fdout);
		}
		environ = ft_sstrdup(data->env);
		execve(execpath, argv, environ);
	}
	else
	{
		g_pid = pid;
		if (data->fdin != STDIN)
			close(data->fdin);
		if (data->fdout != STDOUT)
			close(data->fdout);
		else
		{
			waitpid(pid, &status, 0);
			builtin_setenv((char*[3]){"?", ft_itoa(status)}, data);
		}
	}
	return (0);
}
