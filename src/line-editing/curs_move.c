/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_forward.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:21:08 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:23:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Move the cursor forward (right/down)
*/

void		curs_forward(t_curs *curs, int offset)
{
	int		size;
	int		div;
	int		mod;

	size = (curs->li * curs->win_co + curs->co) + offset;
	div = size / curs->win_co;
	mod = size % curs->win_co;
	curs_goto(curs, div, mod);
}

/*
 * Move the cursor backward (left/up)
*/

void		curs_backward(t_curs *curs, int offset)
{
	int		size;
	int		div;
	int		mod;

	size = (curs->li * curs->win_co + curs->co) - offset;
	div = size / curs->win_co;
	mod = size % curs->win_co;
	curs_goto(curs, div, mod);
}
