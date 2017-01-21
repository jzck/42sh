/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rs_setup.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 23:08:04 by ariard            #+#    #+#             */
/*   Updated: 2017/01/22 00:33:27 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		rs_setup(t_script *script)
{
	ft_bzero(script, sizeof(script));
	script->buffer = 0;
	script->b_size = 0;
	script->used = 0;
	script->q_size = 0;
	return (0);
}
