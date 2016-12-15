/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_builtin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 13:09:57 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/15 17:48:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stof g_builtin[] = {
	{"echo", &builtin_echo},
	{"cd", &builtin_cd},
	{"setenv", &builtin_setenv},
	{"unsetenv", &builtin_unsetenv},
	{"env", &builtin_env},
	{"exit", &builtin_exit},
	{"jobs", &builtin_jobs},
	{NULL, NULL},
};

t_execf		*is_builtin(t_process *p)
{
	int		i;

	i = -1;
	while (g_builtin[++i].name)
		if (ft_strcmp(g_builtin[i].name, p->argv[0]) == 0)
			return (g_builtin[i].f);
	return (NULL);
}
