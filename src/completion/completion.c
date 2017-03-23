/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   completion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/20 14:50:33 by alao              #+#    #+#             */
/*   Updated: 2017/03/23 18:58:47 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Function to select the next item in the list if it has already been created
** and if the key pressed is tab.
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
** Once the completion has been processed, this is the return point.
** The three condition are as follow:
** - If the completion list is empty (NULL), the screen is cleared and (1) is
**   returned.
** - If the list contain only one element, c_updater() is called to update the
**   string in the struct data then (1) is returned.
** - If the list contain multiple element that mean the completion is not yet
**   finished so the c_term_mv_down() drop the terminal to make room for the
**   list to be printed using c_printer() and the position is restored by
**   calling c_term_mv_back(). (0) s returned because the command doesn't need
**   an update to be done.
**
** RETURN VALUE :
** If the function return (1), the line edition module will update the command.
*/

int				c_dispatcher(t_data *s)
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
**  The autocompletion module work like the one found in ZSH. Meaning you can
**  select the element in a list and complet the command. You can also move in
**  it using arrows. It can rematch and update the list of choice with a new
**  input from the user. The globbing is also supported. It will also complete
**  path (adding /) and solve dots path.
**  The completion module work for relative, absolute path and binary from the
**  PATH. The env completion is also supported ($[tab]).
**
**  The module start by checking if a globbing should be done using
**  c_glob_matching(). If so, (1) is returned which trigger an update.
**  If the completion structure (later called comp) doesn't exist, the
**  function will check for a few things. If the current position is zero, it
**  will return immediately. Same thing apply if the current position of the
**  cursor is not a space. If those condition are not met the comp struct is
**  created using c_init().
**
**  If the comp struct already exist at the call of the function, the first
**  thing done is checking if the terminal have been resized between call to
**  update the corresponding var. Then it will check which key has been pressed.
**
**  If the tab key has been used, that mean an other item should be selected.
**  This is done using c_next_item(). If the keypress is not tab, c_keypress()
**  is called to process the new key.
**
**  The c_dispatcher() is called which will print or update the command
**  depending on their respective condition.
*/

int				completion(long int keypress)
{
	t_data		*s;
	int			pos;

	s = data_singleton();
	pos = s->line.pos;
	if (c_glob_matching())
		return (1);
	if (s->comp == NULL)
	{
		if (!pos || (s->line.input[pos] != ' ' && s->line.input[pos] != '\0'))
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
		else if (c_keypress(s->comp, keypress))
			return (1);
	}
	return (c_dispatcher(s));
}
