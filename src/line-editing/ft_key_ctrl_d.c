/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key_ctrl_d.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/10 13:44:24 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/08 15:56:51 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line_editing.h"

int		ft_key_ctrl_d(t_data *data, char *buf)
{
	(void)data;
	(void)buf;
	ft_putendl("exit");
	builtin_exit("exit", (char *[]){"exit", NULL}, data_singleton()->env);
	ft_prompt();
	return (0);
}
