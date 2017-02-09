/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregate_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:39:18 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 18:10:13 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//descente recursive pour multi aggregation

int			aggregate_sym(t_sym stack, t_sym *new_sym)
{
	int		k;

	if (stack == 0 && *new_sym == CMD_NAME)
	{
		new_sym = SIMPLE_COMMAND;	
		k = aggregate_sym(stack, new_sym);
		return (k);
	}
	if (stack == SIMPLE_COMMAND && *new_sym == PROGRAM)
	{
		new_sym = PROGRAM
	}
	return  (0);

}
