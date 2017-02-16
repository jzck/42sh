/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_files.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:31:21 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 12:04:10 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** If the parsing for local file fail. The function is called to check if the
** match is actually a folder. If so, the command is updated with a trailing
** slash (/).
**     Exemple:       cd folder[tab]      to      cd folder/
*/

static int		c_exclusion_folder(t_comp *c)
{
	DIR			*rep;
	char		*tmp;

	tmp = ft_strjoin(c->cpath, c->match);
	if ((rep = opendir(tmp)) && (!closedir(rep)))
	{
		tmp ? ft_memdel((void *)&tmp) : (0);
		tmp = ft_strjoin(c->rcmd, "/");
		if (c->trail)
			data_singleton()->line.input = ft_strjoin(tmp, c->trail);
		else
			data_singleton()->line.input = ft_strdup(tmp);
		data_singleton()->line.pos = data_singleton()->line.pos + 1;
		c->isfolder = 1;
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}
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
	rt = (i == (int)ft_strlen(tmp) - 1) ? NULL : ft_strsub(tmp, 0, i);
	if (i <= (int)ft_strlen(tmp) - i + 1)
		c->match = ft_strsub(tmp, i, ft_strlen(tmp) - i);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (rt);
}

/*
** Files searching
*/

int				c_seek_files(t_data *s, t_comp *c)
{
	char	*path;

	(void)s;
	if (c->cpath == NULL)
	{
		path = c_slicer(c);
		c->cpath = path_solver(c, path, NULL);
		path ? ft_memdel((void *)&path) : (0);
	}
	c_parser(c, c->cpath, c->match);
	if (c->lst == NULL)
		c_exclusion_folder(c);
	return (0);
}
