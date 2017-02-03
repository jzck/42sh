/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_files.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:31:21 by alao              #+#    #+#             */
/*   Updated: 2017/01/11 14:06:50 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Clear the binary from c->rcmd ans save the result in c->match. Return the
** path part of it if exist or NULL.
*/

static char		*c_slicer(t_comp *c)
{
	char		*tmp;
	char		*rt;
	int			i;

	i = 0;
	tmp = NULL;
	rt = NULL;
	while (c->rcmd[i] != ' ')
		i++;
	c->rcmd[i] == ' ' ? i++ : (0);
	if (i == (int)ft_strlen(c->rcmd))
		return (NULL);
	tmp = ft_strsub(c->rcmd, i, ft_strlen(c->rcmd) - i);
	i = ft_strlen(tmp) - 1;
	while (i > 0 && tmp[i] && tmp[i] != '/')
		i--;
	tmp[i] == '/' ? i++ : (0);
	rt = ft_strsub(tmp, 0, i);
	if (i <= (int)ft_strlen(tmp) - i + 1)
		c->match = ft_strsub(tmp, i, ft_strlen(tmp) - i);
	DG("From [%s] to path [%s] and match [%s]", tmp, rt, c->match);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (rt);
}

/*
** Files searching
*/

int				c_seek_files(t_data *s, t_comp *c)
{
	DG("Seek Files");
	(void)s;
	char	*path;

	path = c_slicer(c);
	c->cpath = path_solver(c, path, NULL);
	DG("Solved as [%s]", c->cpath);
	path ? ft_memdel((void *)&path) : (0);
	c_parser(c, c->cpath, c->match);
	return (0);
}
