/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 17:23:59 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 17:13:41 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define SHELL_USAGE1	"usage: 42sh [--no-jobcontrol]"
#define SHELL_USAGE2	"   or  42sh -c command"
#define SHELL_USAGE3	"   or  42sh script"

static t_cliopts	g_opts[] =
{
	{'c', NULL, SH_OPTS_LC, SH_OPTS_JOBC | SH_INTERACTIVE, get_c_arg, 1},
	{-1, "no-jobcontrol", 0, SH_OPTS_JOBC, NULL, 0},
	{0, 0, 0, 0, 0, 0},
};

int					get_c_arg(char *opt_arg, t_data *data)
{
	if (!opt_arg)
		return (1);
	if (data)
		data->c_arg = opt_arg;
	return (0);
}

static int			get_input_fd(t_data *data, char *file)
{
	static int	fds[2] = {-1, STDIN};
	struct stat	buf;

	if (data->opts & SH_OPTS_LC && (file = data->c_arg))
	{
		pipe(fds);
		write(fds[PIPE_WRITE], file, ft_strlen(file));
		close(fds[PIPE_WRITE]);
	}
	else if ((file = *data->av_data))
	{
		if (stat(file, &buf) < 0)
			SH_ERR("%s: No such file or directory", file);
		else if (S_ISDIR(buf.st_mode))
			SH_ERR("%s: is a directory", file);
		else if ((fds[PIPE_READ] = open(file, O_RDONLY | O_CLOEXEC)) < 0)
			SH_ERR("%s: No such file or directory", file);
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
	shell_sig_reset();
	if (setpgid(*shell_pgid, *shell_pgid))
	{
		SH_ERR("setpgid(): %s", strerror(errno));
		return (-1);
	}
	tcsetpgrp(STDIN, *shell_pgid);
	tcgetattr(STDIN, &data->jobc.shell_tmodes);
	return (0);
}

int					shell_init(int ac, char **av, char **env)
{
	t_data	*data;

	data = data_singleton();
	if (data_init(ac, av, env) < 0)
		return (-1);
	if (cliopts_get(av, g_opts, data))
		return (ft_perror(NULL)
				&& SH_ERR("%s", SHELL_USAGE1)
				&& SH_ERR("%s", SHELL_USAGE2)
				&& SH_ERR("%s", SHELL_USAGE3));
	if (!isatty(STDIN) || *data->av_data)
		data->opts &= ~(SH_INTERACTIVE | SH_OPTS_JOBC);
	if ((data->fd = get_input_fd(data, NULL)) < 0)
		return (-1);
	if (SH_IS_INTERACTIVE(data->opts) && interactive_settings() < 0)
		return (-1);
	shell_fds_init();
	return (0);
}
