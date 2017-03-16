/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_delone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:13 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/14 17:52:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstdelone(t_dlist **alst, void (*del)(void *, size_t))
{
	t_dlist	*tmp;

	tmp = *alst;
	if (tmp)
	{
		if (del)
			(*del)(tmp->content, tmp->content_size);
		if (tmp->next)
			tmp->next->prev = tmp->prev;
		if (tmp->prev)
			tmp->prev->next = tmp->next;
		if (tmp->prev)
			*alst = tmp->prev;
		else
			*alst = tmp->next;
		free(tmp);
	}
}
