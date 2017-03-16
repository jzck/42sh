/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arrow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:04:42 by alao              #+#    #+#             */
/*   Updated: 2017/03/16 10:19:54 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Calculate the offset id value from the current one relative to the list size.
** lst_modulo is the number in element in the last column of the list that is
** not perfectly in the same size.
*/

static int	c_idsolver(t_comp *c, int ids, int ids_bk)
{
	int		lst_modulo;

	lst_modulo = c->lst->prev->id % c->c_line;
	if (lst_modulo == 0)
		lst_modulo = c->c_line;
	if (ids > c->lst->prev->id)
	{
		ids -= c->lst->prev->id;
		if (ids_bk < ((c->lst->prev->id - lst_modulo) + 1))
			ids = ids + lst_modulo;
		else
			ids = ids - (c->c_line - lst_modulo);
	}
	else if (ids < c->lst->id)
	{
		if (ids_bk <= lst_modulo)
			ids = (c->lst->prev->id - lst_modulo) + ids_bk;
		else
			ids = c->lst->prev->id - (ids * -1) - lst_modulo;
		if (ids < c->lst->id)
			ids = 1;
	}
	return (ids);
}

/*
** Determine the movement in the list by retrieving the current id selected in
** the list and add/substract the value depending on the keypress (left/right).
** Call for c_idsolver() to adjust this value and cycle in the list to reassign
** the correct element to cursor position.
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
** Arrow support for moving inside the list of the completion.
** If the keypress is left/right, c_arrow_multi() is called. Else the list is
** just read until the cursor is found and the next/prev is reassigned as
** selected.
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
