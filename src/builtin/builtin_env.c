/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:14:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/17 11:06:40 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
**	a ajouter dans la lib ?
*/

int		ft_sstr_found(char **sstr, char *name)
{
	int		size;

	size = 0;
	if (sstr)
		while (sstr[size] && ft_strncmp(name, sstr[size], ft_strlen(name)))
			++size;
	return (size);
}

void	ft_sstr_freeone(char **sstr, int index)
{
	char	*tmp;

	if (!sstr || !sstr[index])
		return ;
	tmp = sstr[index];
	while (sstr[index])
	{
		sstr[index] = sstr[index + 1];
		index++;
	}
	free(tmp);
}

/*
**
*/

static void	ft_env_execute(char *const argv[], char **env)
{
	pid_t	soon;
	char	*path;
	char	*path_exe;

	path = ft_getenv(env, "PATH");
	path_exe = ft_findexec(path, *argv);
	if (!path || !path_exe)
	{
		ft_dprintf(2, "{red}%s: no such file or directory: %s{eoc}\n",
				SHELL_NAME, *argv);
		return ;
	}
	if ((soon = fork()))
		wait(&soon);
	else
		set_exitstatus(execve(path_exe, argv, env), 1);
	free(path_exe);
}

static void	ft_illegal_opt_env(char c)
{
	ft_dprintf(2, "{red}env: option requires an argument -- %c\n", c);
	ft_dprintf(2, "usage: env\t[-iv] [-P utilpath] [-S string]");
	ft_dprintf(2, " [-u name]\n\t\t[name=value ...] ");
	ft_dprintf(2, "[utility [argument ...]]{eoc}\n");
}

static int	ft_check_env_opt(char ***argv, char ***env)
{
	if (!ft_strcmp(**argv, "-i"))
	{
		ft_sstrfree(*env);
		*env = NULL;
		++(*argv);
	}
	else if (!ft_strcmp(**argv, "-u"))
	{
		++(*argv);
		if (!**argv)
		{
			ft_illegal_opt_env('u');
			return (1);
		}
		ft_sstr_freeone(*env, ft_sstr_found(*env, **argv));
		++(*argv);
	}
	else if (***argv == '-')
	{
		ft_illegal_opt_env(*(**argv + 1));
		return (1);
	}
	return (0);
}

int			builtin_env(const char *path, char *const argv[], char *const envp[])
{
	char	**env;

	(void)path;
	env = ft_sstrdup((char **)envp);
	while (*argv)
	{
		if (ft_check_env_opt((char ***)&argv, (char ***)&env))
			break ;
		while (*argv && ft_strrchr(*argv, '='))
		{
			env = ft_sstradd(env, *argv);
			++argv;
		}
		if (env && (!*argv || (!ft_strcmp(*argv, "env") && !*(argv + 1))))
		{
			ft_sstrprint(env, '\n');
			ft_putchar('\n');
			return (0);
		}
		if (*argv && ft_strcmp(*argv, "env"))
		{
			ft_env_execute(argv, env);
			return (0);
		}
		if (*argv)
			++argv;
	}
	ft_sstrfree(env);
	return (0);
}
