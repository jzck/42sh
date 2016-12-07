/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:14:20 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:28:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_env(char **av, t_data *data)
{
	int		i;
	char	**env;

	i = 1;
	env = NULL;
	if (!av[1])
	{
		ft_sstrprint(data->env, '\n');
		ft_putchar('\n');
	}
	else
	{
		while (av[i] && ft_strchr(av[i], '='))
		{
			env = ft_sstradd(env, av[i]);
			i++;
		}
		if (av[i])
			ft_cmd_process(av + i, data);
	}
	return (0);
}
