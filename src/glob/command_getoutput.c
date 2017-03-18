/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:44:25 by wescande          #+#    #+#             */
/*   Updated: 2017/03/18 04:11:20 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define BUF_SIZE	1024

static char		*manage_output(int *fds)
{
	int			ret;
	char		buf[BUF_SIZE + 1];
	char		*output;

	output = NULL;
	close(fds[PIPE_WRITE]);
	while ((ret = read(fds[PIPE_READ], buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		ft_strappend(&output, buf);
	}
	close(fds[PIPE_READ]);
	return (output);
}

static char		*manage_command(char *const av_cmd[])
{
	char	*command;
	int		i;

	if (!av_cmd)
		return (NULL);
	i = -1;
	command = ft_strdup(av_cmd[++i]);
	while (av_cmd[++i])
		ft_strjoin(command, av_cmd[i]);
	return (command);
}

char			*command_getoutput(char *command, char *const av_cmd[], char **env)
{
	char		*output;
	int			ret;
	int			pid;
	int			fds[2];
	char		**av;

	pipe(fds);
	if (!(pid = fork()))
	{
		close(fds[PIPE_READ]);
		dup2_close(fds[PIPE_WRITE], STDOUT);
		av = ft_sstradd(NULL, data_singleton()->argv[0]);
		av = ft_sstradd(av, "-c");
		if (!(command = command ? command : manage_command(av_cmd)))
			exit(1);
		DG("command is %s", command);
		av = ft_sstradd(av, command);
		execve(data_singleton()->argv[0], av, env);
		exit(1);
	}
	waitpid(pid, &ret, WUNTRACED);
	output = manage_output(fds);
	return (output);
}
