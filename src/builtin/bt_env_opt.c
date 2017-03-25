/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bt_env_opt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/25 20:39:54 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/25 21:21:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			bt_env_opt_i(char *opt_arg, t_env_data *data)
{
	(void)opt_arg;
	ft_tabdel(&data->custom_env);
	return (0);
}

int			bt_env_opt_u(char *opt_arg, t_env_data *data)
{
	int		i;
	char	**env;

	if (!(env = data->custom_env))
		return (0);
	i = -1;
	while (env[++i])
	{
		if (ft_strcmp(env[i], opt_arg) == '='
				&& ft_strlen(opt_arg) == ft_strlenchr(env[i], '='))
			ft_sstrdel(env, i);
	}
	return (0);
}
