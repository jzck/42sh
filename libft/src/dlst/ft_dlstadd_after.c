/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_add_after.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:04 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:27:36 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dlstadd_after(t_dlist **alst, t_dlist *new)
{
	if (new)
	{
		new->prev = (*alst);
		if (*alst)
			new->next = (*alst)->next;
		else
			new->next = NULL;
		if (new->next)
			new->next->prev = new;
		if (new->prev)
			new->prev->next = new;
		*alst = new;
	}
}
