/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_script.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 22:49:31 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 00:33:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_read_script()
{
	t_script	*script;

	script = &data_singleton()->script;
	if (rs_setup(script) < 0)
		return (-1);
//	if (rs_loop(script) < 0)
//		return (-1);
	return (0);
}
