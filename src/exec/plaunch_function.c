/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/23 06:19:00 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FUNCERR_0	":maximum nested function level reached"
#define FUNC_LVL	200

int				plaunch_function(t_process *p)
{
	static int 	protection= 0;
	/* char		*val; */

	/* if (ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL"))  > FUNC_LVL) */
	/* 	return(SH_ERR(FUNCERR_0)); */

	if (protection >= FUNC_LVL)
		return(SH_ERR(FUNCERR_0));
	protection++;

// jack faut qu on parle
	/* val = ft_itoa(ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL")) + 1); */
	/* builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL", val, NULL}, NULL); */
	/* ft_strdel(&val); */
	ft_exec(&p->data.function.content);
	/* val = ft_itoa(ft_atoi(ft_getenv(data_singleton()->env, "FUNC_LVL")) - 1); */
	/* builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL", val, NULL}, NULL); */
	/* ft_strdel(&val); */
	protection--;
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
