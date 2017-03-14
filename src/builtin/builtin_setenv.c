/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jhalford@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/14 22:44:18 by ariard           ###   ########.fr       */
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
	if (ft_strcmp(av[0], "setenv") == 0
		|| ft_strcmp(av[0], "export") == 0
		|| ft_strcmp(av[0], "local") == 0)
		av++;
	if (!av[0])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else
	{
		DG("str3join(%s,%s,%s)", av[0], "=", av[1]);
		str = ft_str3join(av[0], "=", av[1]);
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
