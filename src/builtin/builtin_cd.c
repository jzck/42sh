/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:57:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 14:29:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

#define CDOPT_L	(1 << 0)
#define CDOPT_P	(1 << 2)
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)
#define CDERR_1 "cd: no such file or directory: %s\n"

static char		*builtin_cd_special(char *const av[], char *const env[])
{
	char	*target;

	if (!*av)
	{
		if (!(target = ft_getenv((char**)env, "HOME")))
			return (NULL);
	}
	else if (ft_strcmp(*av, "-") == 0)
		target = ft_getenv((char**)env, "OLDPWD");
	else
		target = *av;
	return (target);
}

static int		builtin_cd_opts(char *const av[], int *opts)
{
	int		i;
	int		j;
	int		tmp_opts;

	i = 1;
	tmp_opts = 0;
	if (av)
		while (av[i] && av[i][0] == '-' && av[i][1])
		{
			j = 0;
			while (av[i][++j])
			{
				if (av[i][j] == 'P')
					tmp_opts |= CDOPT_P;
				else if (av[i][j] == 'L')
					tmp_opts |= CDOPT_L;
				else
					return (i);
			}
			*opts |= tmp_opts;
			i++;
		}
	return (i);
}

int				builtin_cd(const char *path, char *const av[], char *const envp[])
{
	int		i;
	int		opts;
	char	*target;

	opts = 0;
	i = builtin_cd_opts(av, &opts);
	if (!(target = builtin_cd_special(av + i, envp)))
		return (0);
	builtin_setenv(path, (char*[3]){"OLDPWD", getcwd(NULL, 0)}, envp);
	if (chdir(target))
	{
		ft_printf(CDERR_1, target);
		return (1);
	}
	else if (target != av[i])
		ft_printf("%s\n", target);
	builtin_setenv(path, (char*[3]){"PWD", getcwd(NULL, 0)}, envp);
	return (0);
}
