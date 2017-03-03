/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:57:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 20:12:45 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

#define CDOPT_L	(1 << 0)
#define CDOPT_P	(1 << 1)
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)
#define CDERR_1 "{red}cd: no such file or directory: %s{eoc}\n"
#define CDERR_2 "{red}cd: HOME not set{eoc}\n"
#define CDERR_3 "{red}cd: too many arguments{eoc}\n"

static char		*builtin_cd_special(char *const av[], char *const env[])
{
	char	*target;

	if (!*av)
	{
		if (!(target = ft_getenv((char**)env, "HOME")))
		{
			ft_dprintf(2, CDERR_2);
			return (NULL);
		}
	}
	else if (*av && *(av + 1))
	{
		ft_dprintf(2, CDERR_3);
		return (NULL);
	}
	else if (ft_strcmp(*av, "-") == 0)
		target = ft_strdup(ft_getenv((char**)env, "OLDPWD"));
	else
		target = *av;
	return (target);
}

static int		builtin_cd_opts(char *const av[], int *opts)
{
	int		i;
	int		j;

	i = 1;
	if (av)
		while (av[i] && av[i][0] == '-' && av[i][1])
		{
			j = 0;
			while (av[i][++j])
			{
				if (av[i][j] == 'P')
					*opts = CDOPT_P;
				else if (av[i][j] == 'L')
					*opts = CDOPT_L;
				else if (av[i][j] == '-')
					return (i + 1);
				else
					return (i);
			}
			++i;
		}
	return (i);
}

int				builtin_cd(const char *path,
							char *const av[], char *const envp[])
{
	int		i;
	int		opts;
	char	*target;
	char	*cwd;

	opts = CDOPT_L;
	i = builtin_cd_opts(av, &opts);
	if (!(target = builtin_cd_special(av + i, envp)))
		return (1);
	cwd = getcwd(NULL, 0);
	builtin_setenv(path, (char*[3]){"OLDPWD", cwd, NULL}, envp);
	free(cwd);
	if (chdir(target))
	{
		ft_dprintf(2, CDERR_1, target);
		return (1);
	}
	else if (target != av[i])
		ft_printf("%s\n", target);
	cwd = getcwd(NULL, 0);
	builtin_setenv(path, (char*[3]){"PWD", cwd, NULL}, envp);
	free(cwd);
	if (!ft_strcmp(*(av + i), "-"))
		free(target);
	return (0);
}
