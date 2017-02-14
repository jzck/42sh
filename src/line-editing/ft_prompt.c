/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:33 by gwojda            #+#    #+#             */
/*   Updated: 2017/02/10 18:19:16 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_git_status(void)
{
	int		pip[2];
	char	*tmp;
	char	*line;
	pid_t	soon;
	char	*exec[] = {"git", "status", "--porcelain", "--branch", NULL};

	pipe(pip);
	if ((soon = fork()))
	{
		wait(&soon);
		if (WEXITSTATUS(soon))
			return (0);
		close(pip[1]);
		get_next_line(pip[0], &line);
		tmp = line;
		if (ft_strrchr(line, '/'))
			line = ft_strdup(ft_strrchr(line, '/') + 1);
		ft_printf("\x1b[38;5;47mgit:(\x1b[38;5;203m%s\x1b[38;5;47m)", line);
		free(tmp);
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
	return (ft_strlen(line) + 8);
}

/*
**ft_printf de la lib bug avec unicode
*/

static int	ft_get_date(void)
{
	time_t		t;
	struct tm	tm;

	t = time(NULL);
	tm = *localtime(&t);
	ft_putstr("\x1b[38;5;242m");
//	ft_putstr("\033[22;32m");
	printf("%.2d:%.2d:%.2d ", tm.tm_hour, tm.tm_min, tm.tm_sec);
	fflush(NULL);
	if (tm.tm_hour >= 8 && tm.tm_hour < 20)
		printf("\x1b[38;5;184m%C ", L'☀');
	else
		printf("\x1b[38;5;184m%C ", L'★');
	fflush(NULL);
	return (10);
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
//	ft_get_date();
	if (ft_getenv(data_singleton()->env, "?") && ft_atoi(ft_getenv(data_singleton()->env, "?")))
		printf("\x1b[38;5;1m%C  ", L'➜');
	else
		printf("\x1b[38;5;10m%C  ", L'➜');
	fflush(NULL);
	ft_putstr("\x1b[38;5;361m");
	ret += ft_currend_dir();
	if (!(ret += ft_git_status()))
		ret += ft_get_date();
	printf("\x1b[38;5;184m%C ", L'›');
	fflush(NULL);
	ft_putstr("\033[22;37m");
	data_singleton()->line.prompt_size = ret + 6;
}
