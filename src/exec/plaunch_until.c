/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_until.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:04:42 by wescande          #+#    #+#             */
/*   Updated: 2017/03/17 20:20:04 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_until(t_process *p)
{
	int		ret;

	ft_exec(&p->data.d_until.condition);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0"))
	{
		ft_exec(&p->data.d_until.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_until.condition);
	}
	return (ret);
}
