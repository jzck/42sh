/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_features.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/02 15:17:28 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/17 10:45:20 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_buff_f6(void)
{
	int ret;

	ret = 0;
	if (read(0, &ret, sizeof(int)) < 0)
		return (-1);
	return (0);
}

int		ft_control_d(void)
{
	if (!STR || STR[0] == '\0')
	{
		ft_putstr("exit\n");
		builtin_exit(NULL, (char*[]){"exit", NULL}, NULL);
		data_singleton()->line.is_prompt ? ft_prompt() : ft_putstr("> ");
	}
	else if (POS < ft_strlen(STR))
		ft_del();
	else
		ft_puttermcaps("bl");
	return (0);
}

int		ft_control_c(void)
{
/*	if (STR)
		ft_current_str(STR, POS);
	ft_putchar('\n');
	set_exitstatus(1, 1);
	ft_prompt();*/
	ft_strdel(&STR);
	POS = 0;
	return (42);
}

int		ft_control_l(void)
{
	ft_clear_window();
	ft_prompt();
	ft_strdel(&STR);
	POS = 0;
	return (0);
}
