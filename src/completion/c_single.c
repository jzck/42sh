/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_single.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alao <alao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:01:22 by alao              #+#    #+#             */
/*   Updated: 2017/01/31 18:57:59 by alao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "completion.h"


int			c_single(t_comp *c)
{
	DG("SINGLE");
	DG("Containing [%s] match [%s] Candidat [%s]", c->rcmd, c->match, c->lst->name);
	char		*tmp;
	char		*rt;
	int			new_pos;

	tmp = NULL;
	rt = NULL;
	new_pos = c->ircmd + (ft_strlen(c->lst->name) - ft_strlen(c->match)) + 1;
	tmp = ft_strsub(c->rcmd, 0, ft_strlen(c->rcmd) - ft_strlen(c->match));
	rt = ft_strjoin(tmp, c->lst->name);
	tmp ? ft_memdel((void *)&tmp) : (0);
	if (c->trail)
	{
		tmp = ft_strjoin(rt, " ");
		rt ? ft_memdel((void *)&rt) : (0);
		rt = ft_strjoin(tmp, c->trail);
	}
	DG("Resulting RCMD as [%s] with new position [%d] from [%d]", rt, new_pos, c->ircmd);
	rt ? ft_memdel((void *)&rt) : (0);
	c_clear(data_singleton());
	return (0);
}
