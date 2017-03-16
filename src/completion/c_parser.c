/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:52:07 by alao              #+#    #+#             */
/*   Updated: 2017/03/16 08:49:22 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

/*
** Add the matching element to the list
*/

void			c_add_to_lst(t_comp *c, t_clst *node)
{
	if (c->lst == NULL)
	{
		c->lst = node;
		node->next = node;
		node->prev = node;
		node->cursor = 1;
		node->id = 1;
	}
	else
	{
		node->id = c->lst->prev->id + 1;
		c->lst->prev->next = node;
		node->prev = c->lst->prev;
		node->next = c->lst;
		c->lst->prev = node;
	}
}

/*
** Determine if the element should be added to the list. If so, the node is
** created and the function above is called to add it.
*/

//TODO: The above function doesn't reject . and .. folder for abs_path. Fix needed.

/*
static int			c_storing(t_comp *c, char *value, unsigned char type)
{
	t_clst			*tmp;

	if (!(c->match && ft_strncmp(".", c->match, 1) == 0) &&
			(ft_strncmp(".", value, 1) == 0 || ft_strncmp("..", value, 2) == 0))
		return (0);
	if (c->match && ft_strnequ(c->match, value, ft_strlen(c->match)) != 1)
		return (0);
	if (!(tmp = (t_clst *)malloc(sizeof(t_clst))))
		return (-1);
	tmp->name = ft_strdup(value);
	tmp->len = ft_strlen(tmp->name);
	tmp->type = (int)type;
	tmp->cursor = 0;
	c_add_to_lst(c, tmp);
	return (0);
}
*/

static int			c_storing(t_comp *c, char *value, unsigned char type)
{
	t_clst			*tmp;

	if (c->match && c->match[0] == '.')
	{
		if (ft_strequ(".", value) || ft_strequ("..", value))
			return (0);
	}
	else
	{
		if (ft_strncmp(".", value, 1) == 0 || ft_strncmp("..", value, 2) == 0)
			return (0);
	}
	if (c->match && ft_strnequ(c->match, value, ft_strlen(c->match)) != 1)
		return (0);
	if (!(tmp = (t_clst *)malloc(sizeof(t_clst))))
		return (-1);
	tmp->name = ft_strdup(value);
	tmp->len = ft_strlen(tmp->name);
	tmp->type = (int)type;
	tmp->cursor = 0;
	c_add_to_lst(c, tmp);
	return (0);
}

/*
** Cycle through the path specified.
*/

int					c_parser(t_comp *c, char *path, char *name)
{
	DIR				*rep;
	struct dirent	*dirc;

	(void)name;
	if (!(rep = opendir(path)))
		return (-1);
	while ((dirc = readdir(rep)))
		c_storing(c, dirc->d_name, dirc->d_type);
	closedir(rep);
	return (0);
}
