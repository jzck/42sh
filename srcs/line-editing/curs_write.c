/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_write.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:52:20 by sbenning          #+#    #+#             */
/*   Updated: 2016/12/09 17:03:41 by sbenning         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Write some buffer to stdout and recalc coordonate (go to next line and scroll if necessary)
*/

void		curs_write(t_curs *curs, char *str, size_t len)
{
	int		size;
	int		div;
	int		mod;
	
	size = (curs->li * curs->win_co + curs->co) + len;
	div = size / curs->win_co;
	mod = size % curs->win_co;
	write(1, str, len);
	curs_goto(curs, div, mod);
}

/*
 * curs_write in video mode
*/

void		curs_video_write(t_curs *curs, char *str, size_t len)
{
	ft_putstr(tgetstr("so", NULL));
	curs_write(curs, str, len);
	ft_putstr(tgetstr("me", NULL));
}

/*
 * curs_write in video mode without moving the cursor
*/

void		curs_video_write_static(t_curs *curs, char *str, size_t len)
{
	ft_putstr(tgetstr("so", NULL));
	curs_write(curs, str, len);
	ft_putstr(tgetstr("me", NULL));
	curs_backward(curs, len);
}

/*
 * curs_write without moving the cursor
*/

void		curs_write_static(t_curs *curs, char *str, size_t len)
{
	curs_write(curs, str, len);
	curs_backward(curs, len);
}
