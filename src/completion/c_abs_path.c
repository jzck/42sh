/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_abs_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 16:54:59 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/09 17:34:43 by gwojda           ###   ########.fr       */
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
		return (1);
	}
	tmp ? ft_memdel((void *)&tmp) : (0);
	tmp ? ft_memdel((void *)&tmp) : (0);
	return (0);
}

void	c_seek_abs_path(t_comp *c, char *current_word)
{
	char	*tmp;

	c->cpath = ft_strndup(current_word, ft_strrchr(c->rcmd, '/') - current_word + 1);
	if (current_word[0] == '~')
	{
		tmp = c->cpath;
		c->cpath = ft_str3join(getenv("PWD"), "/", c->cpath + 2);
		free(tmp);
	}
	!c->match ? c->match = ft_strdupi_w(ft_strrchr(c->rcmd, '/') + 1) : 0;
	c_parser(c, c->cpath, c->match);
	c_exclusion_folder(c);
}
