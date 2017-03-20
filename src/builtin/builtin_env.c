/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:14:20 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/20 20:51:55 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#define US_ENV "env [-i] [-u name] [name=value]... [utility [argument...]]"

static int	env_usage(int arg_miss, char c)
{
	if (arg_miss)
		ft_dprintf(2, "{red}env: option requires an argument -- u{eoc}\n");
	else if (c)
		ft_dprintf(2, "{red}env: illegal option -- %c{eoc}\n", c);
	ft_dprintf(2, "usage: %s\n", US_ENV);
	return (1);
}

static void	env_freeone(char **env, char *arg)
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

static void	env_replace(char ***custom_env, char *arg)
{
	char	**arg_split;

	if ((arg_split = ft_strsplit(arg, '=')))
	{
		env_freeone(*custom_env, *arg_split);
		ft_tabdel(&arg_split);
	}
	*custom_env = ft_sstradd(*custom_env, arg);
}

static int	env_treat_flag(char ***custom_env, char *const *arg[])
{
	while (*(++*arg))
	{
		if (!ft_strcmp(**arg, "-i"))
			ft_tabdel(custom_env);
		else if (!ft_strcmp(**arg, "-u"))
		{
			++*arg;
			if (**arg)
				env_freeone(*custom_env, **arg);
			else
				return (env_usage(1, 0));
		}
		else if (ft_strchr(**arg, '='))
			env_replace(custom_env, **arg);
		else if (!ft_strcmp(**arg, "--"))
		{
			++*arg;
			return (0);
		}
		else if ((**arg)[0] == '-')
			return (env_usage(0, (**arg)[1]));
		else
			return (0);
	}
	return (0);
}

int			builtin_env(const char *path,
							char *const argv[], char *const envp[])
{
	char	**env;
	pid_t	pid;

	(void)path;
	pid = 0;
	if (!argv || ft_strcmp(*argv, "env"))
		return (builtin_return_status(0, env_usage(0, 0)));
	env = ft_sstrdup((char **)envp);
	if (env_treat_flag(&env, &argv))
	{
		ft_sstrfree(env);
		return (builtin_return_status(0, 1));
	}
	if (!*argv)
	{
		ft_sstrprint(env, '\n');
		if (env)
			ft_putchar('\n');
	}
	else
		pid = command_setoutput(argv, env);
	ft_tabdel(&env);
	return (builtin_return_status(pid, 0));
}
