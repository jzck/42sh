/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:33 by alao              #+#    #+#             */
/*   Updated: 2017/03/14 11:22:04 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Function to select the next item in the list if it has already been created
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

int		c_dispatcher(t_data *s)
{
	if (s->comp && s->comp->lst == NULL)
	{
		c_clear(s);
		return (1);
	}
	else if (s->comp && s->comp->lst == s->comp->lst->next)
	{
		c_updater(s->comp, s->comp->lst->name);
		return (1);
	}
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
	if (c_glob_matching())
		return (1);
	if (s->comp == NULL)
	{
		if (s->line.pos == 0)
			return (0);
		if (s->line.input[s->line.pos] != ' ' &&
				s->line.input[s->line.pos] != '\0')
			return (0);
		c_init(s, keypress);
		if (s->comp == NULL)
			return (1);
	}
	else
	{
		c_term_resize(s->comp);
		if (keypress == TOUCHE_TAB)
			c_next_item(s->comp);
		else
		{
			if (c_gtfo(s->comp, keypress))
				return (1);
		}
	}
	return (c_dispatcher(s));
}
