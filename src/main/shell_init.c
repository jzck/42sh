/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/22 16:08:21 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_cliopts	g_opts[] =
{
	{'c', NULL, SH_OPTS_LC, SH_OPTS_JOBC | SH_INTERACTIVE, get_c_arg},
	{-1, "no-jobcontrol", 0, SH_OPTS_JOBC, NULL},
	{0, 0, 0, 0, 0},
};

int					get_c_arg(char ***av, t_data *data)
{
	if (!av || !*av)
		return (1);
	if (data)
		data->c_arg = **av;
	return (0);
}

static int			get_input_fd(t_data *data)
{
	static int	fds[2] = {-1, STDIN};
	char		*file;
	struct stat	buf;

	if (data->opts & SH_OPTS_LC && (file = data->c_arg))
	{
		pipe(fds);
		write(fds[PIPE_WRITE], file, ft_strlen(file));
		close(fds[PIPE_WRITE]);
	}
	else if ((file = *data->av_data))
	{
		DG("file=%s", file);
		if (stat(file, &buf) < 0)
			ft_printf("{red}%s: %s: No such file or directory\n{eoc}",
					data->argv[0], file);
		else if (S_ISDIR(buf.st_mode))
			ft_printf("{red}%s: %s: is a directory\n{eoc}", data->argv[0],
					file);
		else if ((fds[PIPE_READ] = open(file, O_RDONLY | O_CLOEXEC)) < 0)
			ft_printf("{red}%s: %s: No such file or directory\n{eoc}",
					data->argv[0], file);
	}
	else
		return (STDIN);
	if (fds[PIPE_READ] < 0)
		return (-1);
	fds[PIPE_WRITE] = fcntl(fds[PIPE_READ], F_DUPFD_CLOEXEC, 10);
	close(fds[PIPE_READ]);
	return (fds[PIPE_WRITE]);
}

static int			interactive_settings(void)
{
	int		*shell_pgid;
	t_data	*data;

	data = data_singleton();
	shell_pgid = &data->jobc.shell_pgid;
	while (tcgetpgrp(STDIN) != (*shell_pgid = getpgrp()))
		kill(-*shell_pgid, SIGTTIN);
	*shell_pgid = getpid();
	shell_resetsig();
	if (setpgid(*shell_pgid, *shell_pgid))
	{
		ft_dprintf(2,
				"{red}Couldnt put the shell in it's own process group{eoc}\n");
		return (-1);
	}
	tcsetpgrp(STDIN, *shell_pgid);
	tcgetattr(STDIN, &data->jobc.shell_tmodes);
	return (0);
}

static int			usage(void)
{
	ft_dprintf(2, "usage: 42sh [-c command | [<]script] [--no-jobcontrol]\n");
	return (0);
}

int					shell_init(int ac, char **av)
{
	t_data	*data;

	data = data_singleton();
	if (data_init(ac, av) < 0)
		return (-1);
	if (cliopts_get(av, g_opts, data))
	{
		usage();
		return (ft_perror());
	}
	if (!isatty(STDIN) || *data->av_data)
		data->opts &= ~(SH_INTERACTIVE | SH_OPTS_JOBC);
	if ((data->fd = get_input_fd(data)) < 0)
		return (-1);
	if (SH_IS_INTERACTIVE(data->opts) && interactive_settings() < 0)
		return (-1);
	return (0);
}
