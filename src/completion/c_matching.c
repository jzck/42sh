/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_matching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/02/17 12:29:20 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Start the parsing for the autocompletion.
** Check the first char of the c->rcmd for a . or /. to see if it's a local
** path to search even if there's no space in the command.
** If a space is found in the command. The function will assume it's a binary
** completion that is needed. Else the c_seek_files() is called to search for
** local path along with the binary part separated.
** If any of the other part successfully created a list, the c_sizing is called
** and 1 is returned. The last condition also check is the structure still
** exist. It's only when the c_rematch() called it that it can be the case.
** Else 0 is returned.
*/

int			c_matching(t_data *s, t_comp *c)
{
	if (c->rcmd[0] == '.' || c->rcmd[0] == '/')
	{
		c->rcmd[0] == '.' ? c->cpath = path_solver(c, "./", NULL) : 0;
		c->rcmd[0] == '/' ? c->cpath = path_solver(c, "/", NULL) : 0;
		c_parser(c, c->cpath, c->match);
	}
	else if (!(ft_strchr(c->rcmd, ' ')))
		c_seek_binary(s, c);
	else
		c_seek_files(s, c);
	if (s->comp && s->comp->lst)
	{
		c_sizing(c);
		return (1);
	}
	return (0);
}
