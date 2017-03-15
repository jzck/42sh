/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/15 02:12:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_setenv(const char *path, char *const av[], char *const envp[])
{
	char	*str;
	char	***env;
	int		i;

	(void)envp;
	(void)path;
	i = 0;
	env = ft_strcmp(av[0], "local") == 0 ?
		&data_singleton()->local_var : &data_singleton()->env;
	av++;
	if (!av[0])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else
	{
		str = ft_str3join(av[0], "=", av[2]);
		while ((*env) && (*env)[i])
		{
			if (ft_strcmp((*env)[i], av[0]) == '=')
			{
				ft_strdel(&(*env)[i]);
				(*env)[i] = str;
				return (0);
			}
			i++;
		}
		*env = ft_sstradd(*env, str);
		ft_strdel(&str);
	}
	return (0);
}
