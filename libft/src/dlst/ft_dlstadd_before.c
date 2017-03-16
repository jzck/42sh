/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_before.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:09 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:27:10 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_before(t_dlist **alst, t_dlist *new)
{
	if (new)
	{
		new->next = (*alst);
		if (*alst)
			new->prev = (*alst)->prev;
		if (new->next)
			new->next->prev = new;
		if (new->prev)
			new->prev->next = new;
		*alst = new;
	}
}
