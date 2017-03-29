/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_match_update.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:03:30 by alao              #+#    #+#             */
/*   Updated: 2017/03/28 16:13:46 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

static char		*c_current_words(void)
{
	size_t	pos;
	char	*str;

	pos = data_singleton()->line.pos;
	str = data_singleton()->line.input;
	if (pos && c_is_delim(str[pos]))
		--pos;
	while (pos && !c_is_delim(str[pos]))
		--pos;
	if (c_is_delim(str[pos]))
		++pos;
	return (c_strdupi(str + pos, &c_is_delim));
}

/*
** Recreate a c->match value by adding the new key pressed to it.
*/

static int		c_refresh_match(t_comp *c, long int keypress)
{
	char		*tmp;
	char		kpconv[2];
	char		*dump;

	kpconv[0] = (char)keypress;
	kpconv[1] = '\0';
	tmp = c->match ? ft_strjoin(c->match, kpconv) : ft_strdup(kpconv);
	c->match ? ft_memdel((void *)&c->match) : (0);
	dump = c_current_words();
	if (!(ft_strchr(dump, '$')))
		c->match = ft_strdup(tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp = ft_strjoin(c->rcmd, kpconv);
	c->rcmd ? ft_memdel((void *)&c->rcmd) : (0);
	c->rcmd = ft_strdup(tmp);
	c->ircmd++;
	tmp ? ft_memdel((void *)&tmp) : (0);
	dump ? ft_memdel((void *)&dump) : (0);
	return (0);
}

/*
** The function is called when the module already exist and a foreign key is
** pressed (like a new letter). If the input key is on the ascii table, the
** previous display of the list is cleared and a new c->match values is
** created. The previous list is then cleared followed by a call to
** c_seek_files() function which will try to recreate a list. If so, the sizing
** is updated and the function return 1. If the research for a new listing fail
** the function return 0 which will tell the next function to cancel the update
** and clear the module memory.
*/

int				c_rematch(t_comp *c, long int keypress)
{
	t_data		*s;

	s = data_singleton();
	if (ft_isascii(keypress))
	{
		c->isrematch = 1;
		c_term_clear(c);
		c_refresh_match(c, keypress);
		c_clear_lst(c);
		ft_print(keypress, &s->line.input, &s->line.pos);
		c_matching(s, c);
		if (s->comp && c->lst == NULL)
			c_clear(s);
		else if (s->comp && c->lst == c->lst->next)
			return (ft_putchar('\b') + 1);
		return (1);
	}
	else
	{
		c_term_clear(c);
		c_clear(s);
	}
	return (0);
}
