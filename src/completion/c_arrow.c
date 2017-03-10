/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_arrow.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/10 09:04:42 by alao              #+#    #+#             */
/*   Updated: 2017/03/10 10:21:01 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

static void		c_arrow_right(t_comp *c)
{
	t_clst		*ptr;
	int			i;

	ptr = c->lst;
	i = 0;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	while (i < c->c_line)
	{
		ptr = ptr->next;
		if (ptr == c->lst)
			i += c->c_line - (c->c_sy - ((c->c_pline - 1) * c->c_line));
		i++;
	}
	DG("POSX [%d] C_PLINE [%d]", c->pos_x, c->c_line);
	if (c->pos_x == (c->c_pline - 1))
	{
		DG("X");
		i = c->c_line - (c->c_sy - ((c->c_pline - 1) * c->c_line));
		while (i < c->c_line)
		{
			ptr = ptr->next;
			i++;
		}
	}
	ptr->cursor = 1;
}

static void		c_arrow_left(t_comp *c)
{
	t_clst		*ptr;
	int			i;

	ptr = c->lst;
	i = 0;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	while (i < c->c_line)
	{
		ptr = ptr->prev;
		if (ptr == c->lst)
			i += c->c_line - (c->c_sy - ((c->c_pline - 1) * c->c_line));
		i++;
	}
/*	if (c->pos_x == 1)
	{
		i = c->c_line - (c->c_sy - ((c->c_pline - 1) * c->c_line));
		while (i < c->c_line)
		{
			ptr = ptr->prev;
			i++;
		}
	}*/
	ptr->cursor = 1;
}

static void		c_arrow_down(t_comp *c)
{
	t_clst		*ptr;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->next->cursor = 1;
}

static void		c_arrow_up(t_comp *c)
{
	t_clst		*ptr;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->prev->cursor = 1;
}

void		c_arrow(t_comp *c, long int keypress)
{
	if (keypress == 4283163)
		c_arrow_up(c);
	if (keypress == 4348699)
		c_arrow_down(c);
	if (keypress == 4479771)
		c_arrow_left(c);
	if (keypress == 4414235)
		c_arrow_right(c);
}
