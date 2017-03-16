/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:51:33 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/16 10:38:23 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	promt_git_status(int fd)
{
	int		len;
	char	*tmp;
	char	*line;

	get_next_line(fd, &line);
	tmp = line;
	if (ft_strrchr(line, '/'))
		line = ft_strdup(ft_strrchr(line, '/') + 1);
	else
		line = ft_strdup(line + 3);
	free(tmp);
	ft_printf("\x1b[38;5;47mgit:(\x1b[38;5;203m%s\x1b[38;5;47m)", line);
	if (!get_next_line(fd, &tmp))
		ft_printf("\x1b[38;5;83m ✓ ");
	else
	{
		ft_printf("\x1b[38;5;1m ✗ ");
		free(tmp);
	}
	while (get_next_line(fd, &tmp))
		free(tmp);
	free(tmp);
	len = ft_strlen(line);
	ft_strdel(&line);
	return (len + 8);
}

static int	ft_git_status(void)
{
	static char	*exec[] = {"git", "status", "--porcelain", "--branch", NULL};
	int			pip[2];
	pid_t		soon;
	int			ret;

	pipe(pip);
	if ((soon = fork()))
	{
		waitpid(soon, &ret, WUNTRACED);
		if (WEXITSTATUS(ret))
			return (-1);
		close(pip[1]);
		return (promt_git_status(pip[0]));
	}
	else
	{
		dup2(pip[1], 1);
		dup2(pip[1], 2);
		close(pip[0]);
		execve("/usr/bin/git", exec, data_singleton()->env);
	}
	return (0);
}

static int	ft_currend_dir(void)
{
	char	**env;
	char	*pwd;
	char	*currend_dir;

	env = data_singleton()->env;
	if (!(pwd = ft_getenv(env, "PWD")))
		return (-1);
	if (ft_getenv(env, "HOME") && !ft_strcmp(pwd, ft_getenv(env, "HOME")))
	{
		ft_printf("%c ", '~');
		return (1);
	}
	if (!(currend_dir = ft_strrchr(pwd, '/')))
		return (0);
	if (!*(currend_dir + 1))
	{
		ft_printf("%c ", '/');
		return (1);
	}
	ft_printf("%s ", currend_dir + 1);
	return (ft_strlen(currend_dir + 1));
}

void		ft_prompt(void)
{
	int ret;

	ret = 0;
	do_job_notification();
	if (ft_getenv(data_singleton()->env, "?") &&
					ft_atoi(ft_getenv(data_singleton()->env, "?")))
		ft_printf("\x1b[38;5;1m➜  ");
	else
		ft_printf("\x1b[38;5;10m➜  ");
	ft_putstr("\x1b[38;5;361m");
	ret += ft_currend_dir();
	ret += ft_git_status();
	ft_putstr("\033[22;37m");
	data_singleton()->line.prompt_size = ret + 4;
}
