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

static t_cliopts	g_cdopts[] =
{
	{'P', NULL, CD_OPT_P, CD_OPT_L, NULL, 0},
	{'L', NULL, CD_OPT_L, CD_OPT_P, NULL, 0},
	{0, NULL, 0, 0, NULL, 0},
};

static char			*cd_operand_exist(char *arg)
{
	char	*target;

	target = NULL;
	if (!arg)
	{
		if (!(target = ft_strdup(ft_getenv(data_singleton()->env, "HOME"))))
			SH_ERR(CDERR_1, "HOME");
	}
	return (target);
}

static char			*cd_operand_begin(char *arg)
{
	char	*target;

	if (arg && arg[0])
	{
		if (arg[0] == '/')
			target = ft_strdup(arg);
		else if (!ft_strncmp(arg, "./", 2) || !ft_strncmp(arg, "../", 3)
			|| !ft_strcmp(arg, ".") || !ft_strcmp(arg, ".."))
			target = ft_str3join(ft_getenv(data_singleton()->env,
				"PWD"), "/", arg);
		else if (!ft_strcmp(arg, "-"))
		{
			if (!(target = ft_strdup(ft_getenv(data_singleton()->env,
				"OLDPWD"))))
				SH_ERR(CDERR_1, "OLDPWD");
		}
		else
			target = ft_str3join(".", "/", arg);
	}
	else
		target = arg;
	return (target);
}

void				setwd(char *var)
{
	char	*cwd;

	cwd = getcwd(NULL, 0);
	builtin_setenv(NULL, (char*[]){"cd", var, cwd, NULL}, NULL);
	free(cwd);
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
	ret = 0;
	if (cliopts_get((char **)av, g_cdopts, &data))
		return (1);
	if (data.av_data[0] && data.av_data[1])
		return (SH_ERR(CDERR_0) && SH_ERR(CD_USAGE));
	if (!(target = cd_operand_exist(*data.av_data)))
		target = cd_operand_begin(*data.av_data);
	oldpwd = getcwd(NULL, 0);
	if ((ret = bt_cd_process_dotdot(target)))
		builtin_setenv(NULL, (char*[]){"cd", "OLDPWD", oldpwd, NULL}, NULL);
	free(target);
	free(oldpwd);
	return (ret);
}
