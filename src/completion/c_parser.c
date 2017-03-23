/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_parser.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:52:07 by alao              #+#    #+#             */
/*   Updated: 2017/03/23 15:42:30 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

void		c_lst_id(t_comp *c)
{
	t_clst	*lst;
	int		i;

	i = 1;
	lst = c->lst;
	if (!lst)
		return ;
	lst->cursor = 1;
	if (!lst)
		return ;
	while (1)
	{
		lst->id = i;
		lst = lst->next;
		++i;
		if (lst == c->lst)
			break ;
	}
}
/*
** Add the matching element to the list
*/

void		c_add_to_lst(t_comp *c, t_clst *node)
{
	t_clst	*lst;

	lst = c->lst;
	if (c->lst == NULL)
	{
		c->lst = node;
		node->next = node;
		node->prev = node;
	}
	else
	{
		while (ft_strcmp(lst->name, node->name) < 0)
		{
			lst = lst->next;
			if (lst == c->lst)
				break ;
		}
		lst->prev->next = node;
		node->prev = lst->prev;
		node->next = lst;
		lst->prev = node;
		if (lst == c->lst && ft_strcmp(lst->name, node->name) > 0)
			c->lst = node;
	}
}

/*
** Determine if the element should be added to the list. If so, the node is
** created and the function above is called to add it.
*/

static int	c_storing(t_comp *c, char *value, unsigned char type)
{
	t_clst			*tmp;

	if (!(c->match && ft_strncmp(".", c->match, 1) == 0) &&
		(ft_strncmp(".", value, 1) == 0 || ft_strncmp("..", value, 2) == 0))
		return (0);
	if (!ft_strcmp(value, ".") || !ft_strcmp(value, ".."))
		return (0);
	if (c->match && ft_strnequ(c->match, value, ft_strlen(c->match)) != 1)
		return (0);
	if (!(tmp = (t_clst *)ft_malloc(sizeof(t_clst))))
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

int			c_parser(t_comp *c, char *path, char *name)
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
