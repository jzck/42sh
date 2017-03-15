/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:09:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 20:01:03 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stof g_builtin[] =
{
	{"echo", &builtin_echo},
	{"cd", &builtin_cd},
	{"export", &builtin_export},
	{"unset", &builtin_unset},
	{"setenv", &builtin_setenv},
	{"local", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"exit", &builtin_exit},
	{"jobs", &builtin_jobs},
	{"fg", &builtin_fg},
	{"bg", &builtin_bg},
	{"read", &builtin_read},
	{"hash", &builtin_hash},
	{"history", &builtin_history},
	{"math", &builtin_math},
	{NULL, NULL},
};

t_execf		*is_builtin(t_process *p)
{
	int		i;

	DG("in builtin");
	i = -1;
	while (g_builtin[++i].name)
	{
		if (ft_strcmp(g_builtin[i].name, p->data.cmd.av[0]) == 0)
		{
			DG();
			return (g_builtin[i].f);
		}
	}
	return (NULL);
}
