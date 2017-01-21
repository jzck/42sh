/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_goto.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:10:22 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:22:56 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Move the cursor to the given coordonate // scroll screen if line is unreachable
*/

void		curs_goto(t_curs *curs, int li, int co)
{
	if (co >= curs->win_co)
		co = curs->win_co - 1;
	if (li >= curs->win_li)
	{
		ft_putstr(tgetstr("sf", NULL));
		li = curs->win_li - 1;
	}
	ft_putstr(tgoto(tgetstr("cm", NULL), co, li));
	curs->li = li;
	curs->co = co;
}
