/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_new_cd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 02:00:40 by ariard            #+#    #+#             */
/*   Updated: 2017/03/25 16:59:37 by ariard           ###   ########.fr       */
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

static char		*cd_operand_exist(char *arg)
{
	char	*target;

	if (!arg)
	{
		if (!(target = ft_getenv(data_singleton()->env, "HOME")))
			SH_ERR(CDERR_0, "HOME");
	}
	else
		target = arg;
	return (target);
}

static char			*cd_operand_begin(char *arg)
{
	char	*target;

	if (arg && arg[0])
	{
		if (arg[0] == '/')
			target = arg;	
		else if (arg[0] == '.')
			target = ft_str3join(ft_getenv(data_singleton()->env,
				"PWD"), "/", arg); 
		else if (ft_strcmp(arg, "-") == 0)
		{
			 if (!(target = ft_getenv(data_singleton()->env, "OLDPWD")))
				 SH_ERR(CDERR_1, "OLDPWD");
		}
		else
			target = bt_cd_get_cdpath(arg);
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

int					builtin_cd(const char *path, char *const av[],
					char *const envp[])
{
	char			*target;
	t_data_template	data;

	(void)envp;
	(void)path;
	data.flag = CD_OPT_L;
	if (cliopts_get((char **)av, g_cdopts, &data))
		return (1);
	if (data.av_data[0] && data.av_data[1])
		return (SH_ERR(CD_USAGE));
	if (!(target = cd_operand_exist(*data.av_data)))
		return (1);
	setwd("OLDPWD");
	if (!target)
		target = cd_operand_begin(*data.av_data);
	if (HAS_CDOPT_P(data.flag)) 
		bt_cd_process_symlink(target);
	else
		bt_cd_process_dotdot(target);	
	free(target);
	return (0);
}
