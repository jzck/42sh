/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_while.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 17:20:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/20 15:50:29 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int				plaunch_while(t_process *p)
{
	int		ret;

	ret = 0;
	ft_exec(&p->data.d_while.condition);
	while (!(ft_strcmp(ft_getenv(data_singleton()->env, "?"), "0")))
	{
		ft_exec(&p->data.d_while.content);
		ret = ft_atoi(ft_getenv(data_singleton()->env, "?"));
		ft_exec(&p->data.d_while.condition);
	}
	return (ret);
}
