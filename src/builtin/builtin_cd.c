/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:57:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/24 23:03:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CDOPT_L	(1 << 0)
#define CDOPT_P	(1 << 1)
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)
#define CDERR_1 "cd: no such file or directory: %s"
#define CDERR_2 "cd: HOME not set"
#define CDERR_3 "cd: too many arguments{eoc}"

static g_cliopts	g_cdotps =
{
	{'P', NULL, CD_OPT_P, CD_OPT_L, NULL},
	{'L', NULL, CD_OPT_L, CD_OPT_P, NULL},
	{0, NULL, 0, 0, NULL},
}

static char		*builtin_cd_special(char *const av[], char *const env[])
{
	char	*target;

	if (!*av)
	{
		if (!(target = ft_getenv((char**)env, "HOME")))
		{
			SH_ERR(CDERR_2);
			return (NULL);
		}
	}
	else if (*av && *(av + 1))
	{
		SH_ERR(CDERR_3);
		return (NULL);
	}
	else if (ft_strcmp(*av, "-") == 0)
		target = ft_strdup(ft_getenv((char**)env, "OLDPWD"));
	else
		target = *av;
	return (target);
}

void			setwd(char *var)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	builtin_setenv(path, (char*[4]){"setenv", var, cwd, NULL}, envp);
	free(cwd);
}

int				builtin_cd(const char *path,
							char *const av[], char *const envp[])
{
	int		i;
	int		opts;
	char	*target;

	data->flag = CD_OPT_L;
	if (cliopts(av, g_cdopts, &data))
	i = builtin_cd_opts(av, &opts);
	setwd("OLDPWD");
	if (!(target = builtin_cd_special(av + i, envp)))
		return (1);
	if (chdir(target))
	{
		SH_ERR(CDERR_1, target);
		return (1);
	}
	else if (target != av[i])
		ft_printf("%s\n", target);
	setwd("PWD");
	if (!ft_strcmp(*(av + i), "-"))
		free(target);
	return (0);
}
