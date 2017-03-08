/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_matching.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/15 13:27:14 by alao              #+#    #+#             */
/*   Updated: 2017/03/08 16:06:13 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

static int		c_exclusion_folder(t_comp *c)
{
	DIR			*rep;
	char		*tmp;
	char		*tmp2;

	tmp = ft_strjoin(c->cpath, c->match);
	tmp2 = NULL;
	if (tmp[ft_strlen(tmp) - 1] == '/')
		return (0);
	if ((rep = opendir(tmp)) && (!closedir(rep)))
	{
		tmp ? ft_memdel((void *)&tmp) : (0);
		tmp2 = ft_strjoin(c->match, "/");
		c_updater(c, tmp2);
		tmp2 ? ft_memdel((void *)&tmp2) : (0);
		ft_strdel(&c->match);
		c->match = ft_strdup("/");
		return (1);
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}
/*
**	chevron y es-tu ???
*/

int			c_chevron(t_comp *c)
{
	size_t	pos;

	pos = c->ircmd;
	while (pos)
	{
		if (c->rcmd[pos] == '<' || c->rcmd[pos] == '>')
			return (1);
		--pos;
	}
	if (c->rcmd[pos] == '<' || c->rcmd[pos] == '>')
		return (1);
	return (0);
}

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
	char	*tmp;

	if (ft_strchr(c->rcmd, '/'))
	{
		c->cpath = ft_strndup(c->rcmd, ft_strrchr(c->rcmd, '/') - c->rcmd + 1);
		if (c->rcmd[0] == '~')
		{
			tmp = c->cpath;
			c->cpath = ft_str3join(getenv("PWD"), "/", c->cpath + 2);
			free(tmp);
		}
		!c->match ? c->match = ft_strdupi_w(ft_strrchr(c->rcmd, '/') + 1) : 0;
		c_parser(c, c->cpath, c->match);
		c_exclusion_folder(c);
	}
	else if (c->rcmd[0] != '.' && !(ft_strchr(c->rcmd, ' ')) && !c_chevron(c))
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
