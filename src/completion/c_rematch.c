/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rematch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:03:30 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 22:03:42 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Recreate a c->match value by adding the new key pressed to it.
*/

static int		c_refresh_match(t_comp *c, long int keypress)
{
	char		*tmp;
	char		kpconv[2];

	kpconv[0] = (char)keypress;
	kpconv[1] = '\0';
	tmp = c->match ? ft_strjoin(c->match, kpconv) : ft_strdup(kpconv);
	c->match ? ft_memdel((void *)&c->match) : (0);
	c->match = ft_strdup(tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp = ft_strjoin(c->rcmd, kpconv);
	c->rcmd ? ft_memdel((void *)&c->rcmd) : (0);
	c->rcmd = ft_strdup(tmp);
	c->ircmd++;
	tmp ? ft_memdel((void *)&tmp) : (0);
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
	if (ft_isascii(keypress))
	{
		c_term_clear(c);
		c_refresh_match(c, keypress);
		c_clear_lst(c);
		c_matching(data_singleton(), c);
		if (c->lst == NULL)
		{
			c_clear(data_singleton());
			return (1);
		}
		else if (c->lst == c->lst->next)
			return (1);
		else
		{
			ft_print(keypress);
			return(1);
		}
	}
	else
	{
		c_term_clear(c);
		c_clear(data_singleton());
	}
	return (0);
}
