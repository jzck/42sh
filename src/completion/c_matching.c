/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_matching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 15:16:05 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Start the parsing for the autocompletion. If a space is found in the command
** it will call c_seek_files() function. If not, it assume it will be a binary
** so the function c_seek_binary() is called instead.
** Once that done, the printing function should occur.
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
	if (c->lst)
	{
		c_sizing(c);
		return (1);
	}
	return (0);
}
