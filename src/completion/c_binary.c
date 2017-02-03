/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_binary.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:30:57 by alao              #+#    #+#             */
/*   Updated: 2017/02/03 13:30:59 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Retrieve the path from the env and cycle through it to find the matching
** element with the c_parser() function
*/

int				c_seek_binary(t_data *s, t_comp *c)
{
	char		*tmp;
	char		**paths;
	int			i;

	DG("SB: Start");
	i = 0;
	tmp = NULL;
	if (!(tmp = ft_strdup(ft_getenv(s->env, "PATH"))))
		return (-1);
	DG("SB: Path extracted [%s]", tmp);
	paths = ft_strsplit(tmp, ':');
	c->match = ft_strdup(c->rcmd);
	while (paths[i])
		c_parser(c, paths[i++], c->rcmd);
	tmp ? ft_memdel((void *)&tmp) : (0);
	paths ? ft_sstrfree(paths) : (0);
	DG("SB: End");
	return (0);
}
