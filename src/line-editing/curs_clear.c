/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   curs_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenning <sbenning@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 17:28:50 by sbenning          #+#    #+#             */
/*   Updated: 2017/01/21 22:22:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curs.h"

/*
 * Clear screen and keep track of cursoe's coordonate
*/

void		curs_clear(t_curs *curs)
{
	ft_putstr(tgetstr("cl", NULL));
	curs->li = 0;
	curs->co = 0;
}

/*
 * Clear screen after cursor position without moving cursor
*/

void		curs_clear_post(t_curs *curs)
{
	ft_putstr(tgetstr("cd", NULL));
	(void)curs;
}
