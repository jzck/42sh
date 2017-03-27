/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:09:57 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/27 16:03:10 by jhalford         ###   ########.fr       */
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
	{"func", &builtin_func},
	{NULL, NULL},
};

t_execf		*is_builtin(t_process *p)
{
	int		i;

	i = -1;
	while (g_builtin[++i].name)
	{
		if (ft_strcmp(g_builtin[i].name, p->data.cmd.av[0]) == 0)
			return (g_builtin[i].f);
	}
	return (NULL);
}
