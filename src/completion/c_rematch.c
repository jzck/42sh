/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_rematch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/15 12:03:30 by alao              #+#    #+#             */
/*   Updated: 2017/02/15 20:17:55 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"

static int		c_refresh_match(t_comp *c, long int keypress)
{
	DG("Refresh match");
	char		*tmp;
	char		kpconv[2];

	kpconv[0] = keypress;
	kpconv[1] = '\0';
	tmp = c->match ? ft_strjoin(c->match, kpconv) : ft_strdup(kpconv);
	c->match ? ft_memdel((void *)&c->match) : (0);
	c->match = ft_strdup(tmp);
	tmp ? ft_memdel((void *)&tmp) : (0);
	(void)c;
	return (0);
}

static int		c_refresh_list(t_comp *c)
{
	DG("Refresh list");
	t_clst		*ptr;
	t_clst		*ptr_bk;

	ptr = c->lst;
	c->lst->prev->next = NULL;
	c->lst->prev = NULL;
	while (ptr->next)
	{
		DG("Refresh list loop on [%s]", ptr->name);
		if (ft_strncmp(c->match, ptr->name, ft_strlen(c->match)) != 0)
		{
			if (ptr == c->lst)
			{
				c->lst = ptr->next;
				c->lst->prev = NULL;
			}
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			ptr_bk = ptr->next;
			ptr->name ? ft_memdel((void *)&ptr->name) : (0);
			ptr ? ft_memdel((void *)&ptr) : (0);
			ptr = ptr_bk;
		}
		ptr = ptr->next;
	}
	DG("Refresh list end");
	return (0);
}

int				c_rematch(t_comp *c, long int keypress)
{
	if (ft_isascii(keypress))
	{
		c_refresh_match(c, keypress);
		c_refresh_list(c);
	}
	return (0);
}
