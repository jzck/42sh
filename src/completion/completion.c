/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:33 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 14:53:57 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** DEBUG FUNCTION
*/

int				test(t_comp *c)
{
	t_clst		*tmp;
	int			i;

	DG("\tAutocompletion dump");
	i = 1;
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

/*
** Function to select the next item in the list if it has already been Created
** and if the keypressed is tab.
*/

static void		c_next_item(t_comp *c)
{
	t_clst		*ptr;

	ptr = c->lst;
	while (!ptr->cursor)
		ptr = ptr->next;
	ptr->cursor = 0;
	ptr->next->cursor = 1;
}

/*
** If the list is empty after the parsing, all memory is cleared.
** if it detect a single item list, the command is directly updated.
** If none of the above behavior is right, the terminal is dropped down by
** comp->c_line then the list is printed. Once that done, the previous position
** of the cursor is restored.
*/

static int		c_dispatcher(t_data *s)
{
	if (s->comp && s->comp->lst == NULL)
	{
		DG("Empty list, flushing autocompletion");
		c_clear(s);
	}
	else if (s->comp && s->comp->lst == s->comp->lst->next)
		return (c_updater(s->comp));
	else if (s->comp && s->comp->lst != s->comp->lst->next)
	{
		c_term_mv_down(s->comp);
		c_printer(s->comp);
		c_term_mv_back(s->comp);
	}
	return (0);
}

/*
**                          Autocompletion feature.
**
**  If the structure of the completion (later called comp) doesn't exist, the
**  function will check for a few things. If the current position is zero, it
**  will return immediately. Same thing apply if the current position of the
**  cursor is not a space. If those condition are not met the comp struct is
**  created using c_init().
**
**  If the comp struct already exist at the call of the function, it will check
**  which key has been pressed. If the tab key has been used, that mean an other
**  item should be selected. This is done using c_next_item(). If the keypress
**  is not tab, c_gtfo() is called to know if the command should be updated or
**  simply delete all the memory.
**
**  The c_dispatcher() is called which will print or update the command
**  depending on their respective condition.
*/

int				completion(long int keypress)
{
	t_data		*s;

	s = data_singleton();
	DG("\n\n\t\tAutocompletion input key [%d]\n", (int)keypress);
	if (s->comp == NULL)
	{
		if (s->line.pos == 0)
			return (0);
		if (s->line.input[s->line.pos] != ' ' &&
				s->line.input[s->line.pos] != '\0')
			return (0);
		c_init(s, keypress);
	}
	else
	{
		if (keypress == TOUCHE_TAB)
			c_next_item(s->comp);
		else
			return (c_gtfo(s->comp, keypress));
	}
	test(s->comp);
	c_dispatcher(s);
	return (0);
}
