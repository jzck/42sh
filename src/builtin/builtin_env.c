/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 16:20:31 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/25 01:19:51 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define ENV_USAGE	"env [-i] [name=value]... [utility [argument...]]"
#define ENV_NOFILE	"env: %s: No such file or directory"
#define ENV_NOPERM	"env: %s: Permission denied"
# define BT_ENV_LI		(1 << 0)
# define BT_ENV_LU		(1 << 1)

static t_cliopts	g_env_opts[] =
{
	{'i', NULL, 0, 0, &bt_env_opt_i, 0},
	{'u', NULL, 0, 0, &bt_env_opt_u, 1},
	{0, 0, 0, 0, 0},
};

int			bt_env_opt_i(char *opt_arg, t_env_data *data)
{
	(void)opt_arg;
	ft_tabdel(&data->custom_env);
	return (0);
}

static void		env_freeone(char **env, char *arg)
{
	int		i;
	char	*tmp;

	while (env && *env && (i = -1))
	{
		if (ft_strcmp(*env, arg) == '='
				&& ft_strlen(arg) == ft_strlenchr(*env, '='))
		{
			tmp = *env;
			while (*env)
			{
				*env = *(env + 1);
				++env;
			}
			ft_strdel(&tmp);
			return ;
		}
		++env;
	}
}

int			bt_env_opt_u(char *opt_arg, t_env_data *data)
{
	int		i;
	char	*tmp;
	char	**env;
	char	**tmp_env;

	env = data->custom_env;
	while (env && *env && (i = -1))
	{
		if (ft_strcmp(*env, opt_arg) == '='
				&& ft_strlen(opt_arg) == ft_strlenchr(*env, '='))
		{
			tmp = *env;
			tmp_env = env + 1;
			while (*env)
			{
				*env = *(env + 1);
				++env;
			}
			env = tmp_env;
			ft_strdel(&tmp);
		}
		++env;
	}
	return (0);
}

static int			bt_env_getcustom(char ***av, t_env_data *data)
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

static int			bt_env_parse(t_env_data *data, char **av)
{
	data->flag = 0;
	data->av_data = NULL;
	data->custom_env = ft_sstrdup(data_singleton()->env);
	if (cliopts_get(av, g_env_opts, data))
		return (1);
	bt_env_getcustom(&data->av_data, data);
	if (!(data->flag & BT_ENV_LI))
	{
		data->custom_env = ft_sstrmerge(data_singleton()->env, data->custom_env);
	}
	return (0);
}

int					builtin_env(const char *path,
							char *const argv[], char *const envp[])
{
	t_env_data	dat;
	int			status;
	pid_t		pid;

	(void)envp;
	if (bt_env_parse(&dat, (char**)argv))
		return (ft_perror("env") && SH_ERR("usage: %s", ENV_USAGE));
	if (!*dat.av_data)
	{
		ft_sstrprint(dat.custom_env, '\n');
		return (ft_putchar('\n') * 0);
	}
	else if ((pid = fork()) == 0)
	{
		if (!(path = ft_strchr(dat.av_data[0], '/') ? ft_strdup(dat.av_data[0])
					: ft_hash(dat.av_data[0])) || access(path, F_OK) != 0)
			exit(SH_ERR(ENV_NOFILE, dat.av_data[0]));
		if (is_directory(path) || access(path, X_OK) != 0)
			exit(SH_ERR(ENV_NOPERM, dat.av_data[0]));
		execve(path, dat.av_data, dat.custom_env);
	}
	waitpid(pid, &status, 0);
	ft_sstrfree(dat.custom_env);
	tcsetpgrp(STDIN, data_singleton()->jobc.shell_pgid);
	return (WIFEXITED(status) ? WEXITSTATUS(status) : 128 + WTERMSIG(status));
}
