/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_output.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 13:10:38 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 18:02:47 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

static int		c_updater_rcmd(t_comp *c)
{
	char		*tmp;
	char		*tmp2;
	int			new_pos;

	tmp = ft_strjoin(c->start, c->between);
	tmp2 = ft_strjoin(tmp, c->rcmd);
	c->rcmd ? ft_memdel((void *)&c->rcmd) : (0);
	c->rcmd = ft_strjoin(tmp2, c->trail);
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp2 ? ft_memdel((void *)&tmp2) : (0);
	data_singleton()->line.input ? ft_memdel((void *)&data_singleton()->line.input) : (0);
	data_singleton()->line.input = ft_strdup(c->rcmd);
	new_pos = ft_strlen(c->start) + ft_strlen(c->between) + ft_strlen(c->rcmd);
	data_singleton()->line.pos = new_pos;
	return (1);
}

/*
** Output function. Will update the data->line.input along with the
** position of the cursor in data->line.pos. If the autocompletion occur in
** the middle of the command, it will join the trailing part of it. Therefor
** recreating the commands completed.
** Once that done, it will clear all the memory related and return one for the
** line edition module which will then trigger an update on the command line.
*/

int				c_updater(t_comp *c, char *select)
{
	char		*tmp;
	char		*rt;

	tmp = NULL;
	rt = NULL;
	if (c->match)
		tmp = ft_strsub(c->rcmd, 0, ft_strlen(c->rcmd) - ft_strlen(c->match));
	else
		tmp = ft_strdup(c->rcmd);
	rt = ft_strjoin(tmp, select);
	tmp ? ft_memdel((void *)&tmp) : (0);
	c->rcmd ? ft_memdel((void *)&c->rcmd) : (0);
	c->rcmd = ft_strdup(rt);
	c_updater_rcmd(c);
	rt ? ft_memdel((void *)&rt) : (0);
	c_clear(data_singleton());
//	DG("Module complete commands [%s] with pos [%d]", data_singleton()->line.input, data_singleton()->line.pos);
	return (1);
}

/*
** Keypress handling function.
**
** The function will determine the right behavior depending on the key pressed
**   If a delete key is called, the function will clear all the line and delete
** the module memory.
**   if a validation key is called, the function will search for the selected
** node and call c_updater().
**   If none of the above behavior is right, the function will call for
** c_rematch() which will recreate the list by adding the keypressed to the
** c->match variable.
**
** RETURN VALUE:
**  If the function doesn't require an update of the command line, it will
**  return 0. Else it will return 1.
**
**              Keypress values that cancel the module:
**                               27: Escape
**                              127: Backspace
**                       2117294875: Delete
**
**             Keypress values that validate the choice:
**                               10: Enter
**                               32: Space
*/

int				c_gtfo(t_comp *c, long int keypress)
{
	t_clst		*ptr;

	if (keypress == 27 || keypress == 127 || keypress == 2117294875)
	{
		c_term_clear(c);
		c_clear(data_singleton());
		return (0);
	}
	if (keypress == 10 || keypress == 32)
	{
		ptr = c->lst;
		while (!ptr->cursor)
			ptr = ptr->next;
		c_updater(c, ptr->name);
		return (1);
	}
	return ((c_rematch(c, keypress)) ? (0) : (1));
}
