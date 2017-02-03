/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:33 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 12:30:54 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** DEBUG FUNCTION
*/

int test(t_comp *c)
{
	DG("\tAutocompletion dump");
	int i = 1;
	t_clst *tmp;

	if (!(c->lst))
	{
		DG("Empty list");
		return (0);
	}
	if (c->lst && c->lst->cursor)
		DG("Node [x] ID [%d] [%s]", c->lst->id, c->lst->name);
	else
		DG("Node [ ] ID [%d] [%s]", c->lst->id, c->lst->name);
	if (c->lst->prev != c->lst)
	{
		tmp = c->lst->next;
		while (tmp != c->lst)
		{
			if (tmp->cursor)
				DG("Node [x] ID [%d] [%s]", tmp->id, tmp->name);
			else
				DG("Node [ ] ID [%d] [%s]", tmp->id, tmp->name);
			i++;
			tmp = tmp->next;
		}
	}
	DG("List configuration as:");
	DG("Max value: Length (X) %d Number (Y) %d", c->c_sx, c->c_sy);
	DG("Translated to [%d] Lines and [%d] Column", c->c_line, c->c_pline);
	return (0);
}

static void	c_next_item(t_comp *c)
{
	t_clst	*ptr;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->next->cursor = 1;
}

int				completion(long int input)
{
	t_data		*s;

	s = data_singleton();

	DG("\n\n\t\tAutocompletion input key [%d]\n", (int)input);
	if (s->comp == NULL)
	{
		if (s->line.pos == 0)
			return (0);
		if (s->line.input[s->line.pos] != ' ' && s->line.input[s->line.pos] != '\0')
			return (0);
		c_init(s, input);
	}
	else
	{
		if (input == 9)
			c_next_item(s->comp);
		else
			DG("Place holder to clear or put the selection in rcmd");
	}
	test(s->comp);
	if (s->comp && s->comp->lst == NULL)
	{
		DG("Empty list, flushing autocompletion");
		c_clear(s);
	}
	else if (s->comp && s->comp->lst == s->comp->lst->next)
	{
		c_single(s->comp);
		return (1);
	}
	else if (s->comp && s->comp->lst != s->comp->lst->next )
	{
		c_term_mv_down(s->comp);
		c_printer(s->comp);
		c_term_mv_back(s->comp);
	}
	return (0);
}
