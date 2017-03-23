/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/23 16:35:59 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FUNCERR_0	":maximum nested function level reached"
#define FUNC_LVL	200

int				plaunch_function(t_process *p)
{
	static int	protection;

	if (!protection)
		protection = 0;
	if (protection >= FUNC_LVL)
		return (SH_ERR(FUNCERR_0));
	protection++;
	ft_exec(&p->data.function.content);
	protection--;
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
