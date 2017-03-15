/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_sizing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 08:50:26 by alao              #+#    #+#             */
/*   Updated: 2017/03/15 14:25:54 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Get the max length from the list
*/

static void		c_max_length(t_comp *s)
{
	t_clst		*tmp;
	int			max_x;
	int			max_y;

	if (s->lst && s->lst->name && s->lst == s->lst->next)
	{
		s->c_sx = s->lst->len;
		s->c_sy = 1;
	}
	else if (s->lst && s->lst->name)
	{
		max_x = s->lst->len;
		max_y = 1;
		tmp = s->lst->next;
		while (tmp != s->lst)
		{
			(max_x < tmp->len) ? (max_x = tmp->len) : (0);
			max_y++;
			tmp = tmp->next;
		}
		s->c_sx = max_x;
		s->c_sy = max_y;
	}
}

/*
** Determine the number of column and row is possible using the list size
** by adding the length of the name plus 2 for the potential trailing / for
** folder.
*/

int				c_sizing(t_comp *c)
{
	c->lst && c->lst->name ? c_max_length(c) : 0;
	c->c_pline = c->win_x / (c->c_sx + 2);
	c->c_line = 0;
	while (c->c_pline && (c->c_line * c->c_pline) < c->c_sy)
		c->c_line++;
	if ((c->win_x < c->c_sx))
	{
		c->c_pline = 0;
		c->c_line = 0;
	}
	return (0);
}
