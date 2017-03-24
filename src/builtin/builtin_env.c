/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:20:31 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/24 15:11:42 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ENV_USAGE	"env [-i] [name=value]... [utility [argument...]]"
#define ENV_NOFILE	"env: %s: No such file or directory"
#define ENV_NOPERM	"env: %s: Permission denied"

t_cliopts	g_env_opts[] =
{
	{'i', NULL, BT_ENV_LI, 0, bt_env_geti},
	{0, 0, 0, 0, 0},
};

int			bt_env_geti(char ***av, t_env_data *data)
{
	if (!av || !*av || !data)
		return (1);
	while (**av && ft_strchr(**av, '='))
	{
		data->custom_env = ft_sstradd(data->custom_env, **av);
		++(*av);
	}
	--(*av);
	return (0);
}

static int	bt_env_parse(t_env_data *data, char **av)
{
	data->flag = 0;
	data->av_data = NULL;
	data->custom_env = NULL;
	if (cliopts_get(av, g_env_opts, data))
		return (1);
	return (0);
}

int			builtin_env(const char *path,
							char *const argv[], char *const envp[])
{
	t_env_data	data;
	int			status;
	pid_t		pid;
	struct stat	buf;

	(void)envp;
	if (bt_env_parse(&data, (char**)argv))
		return (ft_perror("env") && SH_ERR("usage: %s", ENV_USAGE) ? 0 : 0);
	else if (!*data.av_data)
		return (builtin_setenv(NULL, (char*[]){"setenv", 0}, NULL));
	else if ((pid = fork()) == 0)
	{
		if (!(path = ft_strchr(data.av_data[0], '/') ?
			ft_strdup(data.av_data[0]) : ft_hash(data.av_data[0]))
			|| access(path, F_OK) != 0)
			exit(SH_ERR(ENV_NOFILE, data.av_data[0]));
		stat(path, &buf);
		if (S_ISDIR(buf.st_mode) || access(path, X_OK) != 0)
			exit(SH_ERR(ENV_NOPERM, data.av_data[0]));
		execve(path, data.av_data, data.custom_env);
	}
	waitpid(pid, &status, 0);
	ft_sstrfree(data.custom_env);
	tcsetpgrp(STDIN, data_singleton()->jobc.shell_pgid);
	return (0);
}
