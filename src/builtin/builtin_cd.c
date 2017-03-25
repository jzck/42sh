/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:57:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 02:05:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define BT_CD_L		(1 << 0)
#define BT_CD_P		(1 << 1)
#define CD_USAGE	"usage: cd [-L|-P] [dir]"
#define CDERR_1		"cd: no such file or directory: %s"
#define CDERR_2		"cd: %s not set"
#define CDERR_3		"cd: too many arguments"

static t_cliopts	g_cdopts[] =
{
	{'P', NULL, BT_CD_P, BT_CD_L, NULL},
	{'L', NULL, BT_CD_L, BT_CD_P, NULL},
	{0, NULL, 0, 0, NULL},
};

static char		*bt_cd_target(char *arg)
{
	char	*target;

	if (!arg)
	{
		if (!(target = ft_getenv(data_singleton()->env, "HOME")))
			SH_ERR(CDERR_2, "HOME");
	}
	else if (ft_strcmp(arg, "-") == 0)
	{
		DG("doing -");
		if (!(target = ft_getenv(data_singleton()->env, "OLDPWD")))
			SH_ERR(CDERR_2, "OLDPWD");
	}
	else
		target = arg;
	return (target);
}

void			setwd(char *var)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	builtin_setenv(NULL, (char*[]){"cd", var, cwd, NULL}, NULL);
	free(cwd);
}

int				builtin_cd(const char *path,
							char *const av[], char *const envp[])
{
	char			*target;
	t_data_template	data;

	(void)path;
	(void)envp;
	data.flag = BT_CD_L;
	if (cliopts_get((char**)av, g_cdopts, &data))
		return (ft_perror("cd") && SH_ERR(CD_USAGE));
	if (data.av_data[0] && data.av_data[1])
		return (SH_ERR(CDERR_3) && SH_ERR(CD_USAGE));
	if (!(target = bt_cd_target(*data.av_data)))
		return (1);
	setwd("OLDPWD");
	if (chdir(target))
		return (SH_ERR(CDERR_1, target));
	else if (target != *data.av_data)
		ft_printf("%s\n", target);
	setwd("PWD");
	return (0);
}
