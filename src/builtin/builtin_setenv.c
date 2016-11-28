/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_setenv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:25:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:29:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_setenv(char **av, t_data *data)
{
	char	*str;
	char	**env;

	env = data->env;
	if (ft_strcmp(av[0], "setenv") == 0)
		av++;
	if (!av[0])
		ft_sstrprint(data->env, '\n');
	else
	{
		str = ft_str3join(av[0], "=", av[1]);
		while (*env)
		{
			if (ft_strcmp(*env, av[0]) == '=')
			{
				*env = str;
				return (0);
			}
			env++;
		}
		data->env = ft_sstradd(data->env, str);
	}
	return (0);
}
