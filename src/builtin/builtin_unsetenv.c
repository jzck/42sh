/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_unsetenv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:29:17 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/28 14:29:50 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		builtin_unsetenv(char **av, t_data *data)
{
	char	**env;
	int		i;
	int		j;

	env = data->env;
	/* ft_printf("builtin: %s\n", av[0]); */
	i = 1;
	while (av[i])
	{
		j = 0;
		while (env[j])
		{
			if (ft_strcmp(env[j], av[i]) == '=')
				ft_sstrdel(env, j);
			else
				j++;
		}
		i++;
	}
	return (0);
}
