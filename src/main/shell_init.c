/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/17 21:18:15 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cliopts	g_opts[] =
{
	{'c', NULL, SH_OPTS_LC, SH_OPTS_JOBC | SH_INTERACTIVE, NULL},
	{-1, "no-jobcontrol", 0, SH_OPTS_JOBC, NULL},
	{0, 0, 0, 0, 0},
};

int		get_input_fd(char **av)
{
	t_data		*data;
	char		*file;
	int			fds[2];
	int			fd;
	struct stat	buf;

	data = data_singleton();
	if (SH_IS_INTERACTIVE(data->opts))
		return (STDIN);
	else if (data->opts & SH_OPTS_LC)
	{
		pipe(fds);
		file = *cliopts_getdata(av);
		write(fds[PIPE_WRITE], file, ft_strlen(file));
		close(fds[PIPE_WRITE]);
		dup2_close(fds[PIPE_READ], (fd = 10));
		fcntl(fd, F_SETFD, FD_CLOEXEC);
		return (fd);
	}
	else if ((file = *cliopts_getdata(av)) && !stat(file, &buf))
	{
		fd = -1;
		if (S_ISDIR(buf.st_mode))
			ft_printf("{red}%s: %s: is a directory\n{eoc}", av[0], file);
		else if ((fd = open(file, O_RDONLY | O_CLOEXEC)) < 0)
			ft_printf("{red}%s: %s: No such file or directory\n{eoc}", av[0], file);
		if (fd > 0 && !dup2_close(fd, 10) && (fd = 10))
			return (fd);
	}
	return (STDIN);
}

static int			interactive_settings(void)
{
	int		*shell_pgid;
	t_data	*data;

	data = data_singleton();
	shell_pgid = &data->jobc.shell_pgid;
	while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
		kill(-*shell_pgid, SIGTTIN);
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCHLD, SIG_IGN);
	*shell_pgid = getpid();
	if (setpgid(*shell_pgid, *shell_pgid))
	{
		ft_dprintf(2, "Couldnt put the shell in it's own process group");
		exit(1);
	}
	tcsetpgrp(STDIN, *shell_pgid);
	tcgetattr(STDIN, &data->jobc.shell_tmodes);
	return (0);
}

int					shell_init(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	data_init(ac, av);
	if (isatty(STDIN) && !*cliopts_getdata(av))
	{
		data->opts |= SH_INTERACTIVE;
		data->opts |= SH_OPTS_JOBC;
	}
	if (cliopts_get(av, g_opts, data))
		return (ft_perror());
	data->fd = get_input_fd(av);
	if (SH_IS_INTERACTIVE(data->opts))
		interactive_settings();
	return (0);
}
