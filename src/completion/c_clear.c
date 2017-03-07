/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_clear.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:37:43 by alao              #+#    #+#             */
/*   Updated: 2017/02/16 22:03:41 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*
** Clear the list from the memory
*/

int					c_clear_lst(t_comp *c)
{
	t_clst		*c_lst;
	t_clst		*p_lst;

	c_lst = c->lst;
	c->lst->prev ? (c->lst = c->lst->prev) : (0);
	c_lst->prev->next = NULL;
	while (c_lst->next)
	{
		c_lst->name ? ft_memdel((void *)&c_lst->name) : (0);
		c_lst->prev = NULL;
		p_lst = c_lst;
		c_lst = c_lst->next;
		p_lst->next = NULL;
		p_lst ? ft_memdel((void *)&p_lst) : (0);
	}
	c_lst->name ? ft_memdel((void *)&c_lst->name) : (0);
	c_lst ? ft_memdel((void *)&c_lst) : (0);
	c->lst = NULL;
	return (0);
}

/*
** Clear the structure of the autocompletion from the memory and call the above
** function
*/

int					c_clear(t_data *s)
{
	t_comp			*ptr;

	ptr = s->comp;
	ptr->rcmd ? ft_memdel((void *)&ptr->rcmd) : (0);
	ptr->match ? ft_memdel((void *)&ptr->match) : (0);
	ptr->cpath ? ft_memdel((void *)&ptr->cpath) : (0);
	ptr->home ? ft_memdel((void *)&ptr->home) : (0);
	ptr->pwd ? ft_memdel((void *)&ptr->pwd) : (0);
	ptr->start ? ft_memdel((void *)&ptr->start) : (0);
	ptr->between ? ft_memdel((void *)&ptr->between) : (0);
	ptr->trail ? ft_memdel((void *)&ptr->trail) : (0);
	if (ptr->lst && ptr->lst->name)
		c_clear_lst(ptr);
	s->comp ? ft_memdel((void *)&s->comp) : (0);
	s->comp = NULL;
	return (0);
}
