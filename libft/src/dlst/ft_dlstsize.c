/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlst_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 13:27:23 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/07 13:27:23 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_dlstsize(t_dlist *list)
{
	int		size;
	t_dlist	*tmp;

	size = 0;
	if (list)
		size++;
	tmp = list;
	while (tmp->next)
	{
		size++;
		tmp = tmp->next;
	}
	tmp = list;
	while (tmp->prev)
	{
		size++;
		tmp = tmp->prev;
	}
	return (size);
}
