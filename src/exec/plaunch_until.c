/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_until.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 22:04:42 by wescande          #+#    #+#             */
/*   Updated: 2017/03/22 18:04:44 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_until(t_process *p)
{
	int		ret;

	ret = 0;
	ft_exec(&p->data.d_until.condition);
	/* signal(SIGINT, sigint_handler); */
	while (ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0"))
	{
		ft_exec(&p->data.d_until.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_until.condition);
	}
	set_exitstatus(ret, 1);
	return (0);
}
