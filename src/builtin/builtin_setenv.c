/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/27 19:00:07 by jhalford         ###   ########.fr       */
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
	env = &data_singleton()->env;
	if (ft_strcmp(av[0], "setenv") == 0)
		av++;
	if (!av[0])
	{
		ft_sstrprint(*env, '\n');
		ft_putchar('\n');
	}
	else
	{
		str = ft_str3join(av[0], "=", av[1]);
		while ((*env)[i])
		{
			/* DG("check 2: i=%i, (*env)[i]=%p",i, (*env)[i]); */
			/* DG("content=%s", (*env)[i]); */
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
