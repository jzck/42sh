/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plaunch_function.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 03:23:59 by wescande          #+#    #+#             */
/*   Updated: 2017/03/22 19:30:13 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#define FUNCERR_0	SHELL_NAME ":maximum nested function level reached\n"

int				plaunch_function(t_process *p)
{
	char		*temp;
	char		*func_lvl;
	int			value;

	func_lvl = ft_sstrstr(data_singleton()->env, "FUNC_LVL");
	if ((temp = func_lvl))
	{
		func_lvl += ft_strlenchr(func_lvl, '=') + 1;
		if ((value = ft_atoi(func_lvl)) >= 199)
		{
			ft_strdel(&temp);
			return (SH_ERR(FUNCERR_0));
		}
		value += 1;
	}
	else
		value = 0;
	builtin_setenv("setenv", (char *[]){"env", "FUNC_LVL",
		ft_itoa(value), 0}, NULL);
	ft_exec(&p->data.function.content);
	DG();
	return (ft_atoi(ft_getenv(data_singleton()->env, "?")));
}
