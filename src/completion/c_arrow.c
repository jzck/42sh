/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arrow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:04:42 by alao              #+#    #+#             */
/*   Updated: 2017/03/15 14:26:11 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
**
*/

static int	c_idsolver(t_comp *c, int ids, int ids_bk)
{
	if (ids > c->lst->prev->id)
	{
		ids -= c->lst->prev->id;
		if (ids_bk < ((c->lst->prev->id - (c->lst->prev->id % c->c_line)) + 1))
			ids = ids + (c->lst->prev->id % c->c_line);
		else
			ids = ids - (c->c_line - (c->lst->prev->id % c->c_line));
	}
	else if (ids < c->lst->id)
	{
		if (ids_bk <= (c->lst->prev->id % c->c_line))
			ids = (c->lst->prev->id - (c->lst->prev->id % c->c_line)) + ids_bk;
		else
			ids = c->lst->prev->id - (ids * -1) - (c->lst->prev->id % c->c_line);
		if (ids < c->lst->id)
		{
			DG("Failsafe %d", ids);
			ids = 1;
		}
	}
	return (ids);
}

/*
**
*/

static void	c_arrow_multi(t_comp *c, long int keypress)
{
	t_clst	*ptr;
	int		ids;
	int		ids_bk;

	ids = 0;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ids = ptr->id;
	ids_bk = ids;
	(keypress == 4479771) ? (ids -= c->c_line) : (0);
	(keypress == 4414235) ? (ids += c->c_line) : (0);
	ids = c_idsolver(c, ids, ids_bk);
	ptr = c->lst;
	while (ptr->id != ids)
		ptr = ptr->next;
	ptr->cursor = 1;
}

/*
**
*/

void		c_arrow(t_comp *c, long int keypress)
{
	t_clst	*ptr;

	ptr = c->lst;
	if (keypress == 4479771 || keypress == 4414235)
		c_arrow_multi(c, keypress);
	else
	{
		while (!ptr->cursor)
			ptr = ptr->next;
		ptr->cursor = 0;
		(keypress == 4283163) ? (ptr->prev->cursor = 1) : (0);
		(keypress == 4348699) ? (ptr->next->cursor = 1) : (0);
	}
}
