/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_sym.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:26:30 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 17:50:23 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		eval_sym(t_sym stack, t_sym new_sym)
{
//	DG("eval head %s && eval sym %s", read_state(stack), read_state(new_sym));
	if (stack == 0 && new_sym == CMD_NAME)
		return (0);
	if (stack == SYM_GREAT && new_sym == CMD_NAME)
		return (0);
	if (stack == CMD_NAME && new_sym == SYM_GREAT)
		return (0);
	return (1);
}
