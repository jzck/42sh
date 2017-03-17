/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_while.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/17 20:16:10 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_while(t_process *p)
{
	int		ret;

	ft_exec(&p->data.d_while.condition);
	ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
	while (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		ft_exec(&p->data.d_while.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_while.condition);
	}
	return (ret);
}
