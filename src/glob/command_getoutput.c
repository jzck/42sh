/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_getoutput.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/14 19:44:25 by wescande          #+#    #+#             */
/*   Updated: 2017/03/14 19:44:37 by wescande         ###   ########.fr       */
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

char			*command_getoutput(char *command)
{
	char		*output;
	int			ret;
	int			pid;
	int			fds[2];

	if (!command)
		return (NULL);
	pipe(fds);
	if (!(pid = fork()))
	{
		close(fds[PIPE_READ]);
		dup2_close(fds[PIPE_WRITE], STDOUT);
		execle(data_singleton()->argv[0],data_singleton()->argv[0],
				"-c", command, NULL,
				data_singleton()->env);
		exit(1);
	}
	waitpid(pid, &ret, WUNTRACED);
	output = manage_output(fds);
	return (output);
}
