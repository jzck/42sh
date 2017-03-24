/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:20:31 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/24 23:22:19 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ENV_USAGE	"env [-i] [name=value]... [utility [argument...]]"
#define ENV_NOFILE	"env: %s: No such file or directory"
#define ENV_NOPERM	"env: %s: Permission denied"

t_cliopts	g_env_opts[] =
{
	{'i', NULL, BT_ENV_LI, 0, NULL},
	{0, 0, 0, 0, 0},
};

int			bt_env_getcustom(char ***av, t_env_data *data)
{
	if (!av || !*av || !data)
		return (1);
	while (**av && ft_strchr(**av, '='))
	{
		data->custom_env = ft_sstradd(data->custom_env, **av);
		++(*av);
	}
	return (0);
}

static int	bt_env_parse(t_env_data *data, char **av)
{
	data->flag = 0;
	data->av_data = NULL;
	DG();
	if (cliopts_get(av, g_env_opts, data))
		return (1);
	DG();
	data->custom_env = NULL;
	bt_env_getcustom(&data->av_data, data);
	DG();
	if (!(data->flag & BT_ENV_LI))
	{
		DG("no -i");
		data->custom_env = ft_sstrmerge(data_singleton()->env, data->custom_env);
	}
	DG();
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
		return (ft_perror("env") && SH_ERR("usage: %s", ENV_USAGE));
	if (!*data.av_data)
	{
		ft_sstrprint(data.custom_env, '\n');
		ft_putchar('\n');
		return (0);
	}
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
