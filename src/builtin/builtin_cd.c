/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 18:20:42 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 21:23:11 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define CD_OPT_L	(1 << 0)
#define CD_OPT_P	(1 << 1)
#define HAS_CDOPT_P(x) (x & CD_OPT_P)
#define HAS_CDOPT_L(x) (x & CD_OPT_L)
#define CD_USAGE	"usage: cd [-L|-P] [dir]"
#define CDERR_0		"cd: too many arguments"
#define CDERR_1		"cd %s not set"
#define CDERR_2		"cd : %s: No such file or directory"
#define CDERR_3		"cd : %s: Permission denied"
#define CDERR_4		"cd : %s: Not a directory"
#define CDERR_5		"cd : unable to proceed: %s"

static t_cliopts	g_cdopts[] =
{
	{'P', NULL, CD_OPT_P, CD_OPT_L, NULL, 0},
	{'L', NULL, CD_OPT_L, CD_OPT_P, NULL, 0},
	{0, NULL, 0, 0, NULL, 0},
};

int			cd_file_autorisations(char *target, int flag)
{
	(void)flag;
	if (access(target, F_OK))
		return (SH_ERR(CDERR_2, target));
	if (!is_directory(target))
		return (SH_ERR(CDERR_3, target));
	if (access(target, X_OK))
		return (SH_ERR(CDERR_4, target));
	if (chdir(target))
		return (SH_ERR(CDERR_5, target));
	setwd("PWD");
	return (0);
}

static char			*cd_operand_exist(char *arg)
{
	char	*tget;

	tget = NULL;
	if (!arg)
	{
		if (!(tget = ft_strdup(ft_getenv(data_singleton()->env, "HOME"))))
			return (SH_ERR(CDERR_1, "HOME") ? NULL : NULL);
	}
	else
	{
		if (!ft_strcmp(arg, "-"))
		{
			if (!(tget = ft_strdup(ft_getenv(data_singleton()->env, "OLDPWD"))))
				return (SH_ERR(CDERR_1, "OLDPWD") ? NULL : NULL);
			return (tget);
		}
		return (tget = ft_strdup(arg));
	}
	return (tget);
}

void				setwd(char *var)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	builtin_setenv(NULL, (char*[]){"cd", var, cwd, NULL}, NULL);
	ft_strdel(&cwd);
}

int					builtin_cd(const char *path, char *const av[],
					char *const envp[])
{
	char			*oldpwd;
	char			*target;
	t_data_template	data;
	int				ret;

	(void)envp;
	(void)path;
	data.flag = CD_OPT_L;
	if (cliopts_get((char **)av, g_cdopts, &data))
		return (1);
	if (data.av_data[0] && data.av_data[1])
		return (SH_ERR(CDERR_0) && SH_ERR(CD_USAGE));
	if (!(target = cd_operand_exist(*data.av_data)))
		return (1);
	oldpwd = getcwd(NULL, 0);
	if (!(ret = cd_file_autorisations(target, data.flag)))
		builtin_setenv(NULL, (char*[]){"cd", "OLDPWD", oldpwd, NULL}, NULL);
	ft_strdel(&target);
	ft_strdel(&oldpwd);
	return (ret);
}
