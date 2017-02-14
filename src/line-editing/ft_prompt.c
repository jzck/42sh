/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:33 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/14 14:13:05 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_git_status(void)
{
	int		pip[2];
	int		len;
	char	*tmp;
	char	*line;
	pid_t	soon;
	char	*exec[] = {"git", "status", "--porcelain", "--branch", NULL};

	pipe(pip);
	if ((soon = fork()))
	{
		wait(&soon);
		if (WEXITSTATUS(soon))
			return (-1);
		close(pip[1]);
		get_next_line(pip[0], &line);
		tmp = line;
		if (ft_strrchr(line, '/'))
		{
			line = ft_strdup(ft_strrchr(line, '/') + 1);
			ft_printf("\x1b[38;5;47mgit:(\x1b[38;5;203m%s\x1b[38;5;47m)", line);
			free(tmp);
		}
		if (!get_next_line(pip[0], &tmp))
			printf("\x1b[38;5;83m %C ", L'✓');
		else
		{
			printf("\x1b[38;5;1m %C ", L'✗');
			free(tmp);
		}
		fflush(NULL);
	}
	else
	{
		dup2(pip[1], 1);
		dup2(pip[1], 2);
		close(pip[0]);
		execve("/usr/bin/git", exec, data_singleton()->env);
	}
	len = ft_strlen(line);
	ft_strdel(&line);
	return (len + 8);
}

static int	ft_currend_dir(void)
{
	int		i;
	int		j;
	char	**env;

	i = 0;
	env = data_singleton()->env;
	while (ft_strncmp(env[i], "PWD=", 4))
		++i;
	j = ft_strlen(env[i]);
	while (j && env[i][j] != '/')
		--j;
	ft_printf("%s ", env[i] + j + 1);
	return (ft_strlen(env[i] + j + 1));
}

void		ft_prompt()
{
	int 	ret;

	ret = 0;
	do_job_notification();
	if (ft_getenv(data_singleton()->env, "?") && ft_atoi(ft_getenv(data_singleton()->env, "?")))
		printf("\x1b[38;5;1m%C  ", L'➜');
	else
		printf("\x1b[38;5;10m%C  ", L'➜');
	fflush(NULL);
	ft_putstr("\x1b[38;5;361m");
	ret += ft_currend_dir();
	ret += ft_git_status();
	printf("\x1b[38;5;184m%C ", L'›');
	fflush(NULL);
	ft_putstr("\033[22;37m");
	data_singleton()->line.prompt_size = ret + 6;
}
