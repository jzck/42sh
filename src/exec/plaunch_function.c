/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/23 03:15:20 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FUNCERR_0	":maximum nested function level reached"
#define FUNC_LVL	200

int				plaunch_function(t_process *p)
{
	static int 	protection= 0;

	if (ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL"))  > 10)
		return(SH_ERR(FUNCERR_0));

	if (protection >= FUNC_LVL)
		return(SH_ERR(FUNCERR_0));
	protection++;

// jack faut qu on parle
	builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL",
		ft_itoa(ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL")) + 1),
		NULL}, NULL);
	ft_exec(&p->data.function.content);
	builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL",
		ft_itoa(ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL")) - 1),
		NULL}, NULL);
	protection--;
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
