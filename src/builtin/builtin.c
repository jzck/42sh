/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:21:34 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:27:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_stof g_builtin[] = {
	{"echo",		&builtin_echo},
	{"cd",			&builtin_cd},
	{"setenv",		&builtin_setenv},
	{"unsetenv",	&builtin_unsetenv},
	{"env",			&builtin_env},
	{"exit",		&builtin_exit},
	{NULL,			NULL},
};

int		ft_builtin(char **av, t_data *data)
{
	int		i;
	int		ret;

	i = 0;
	while (g_builtin[i].name)
	{
		if (ft_strcmp(g_builtin[i].name, *av) == 0)
		{
			ret = (g_builtin[i].f)(av, data);
			builtin_setenv((char*[3]){"?", ft_itoa(ret)}, data);
			return (1);
		}
		i++;
	}
	return (0);
}
