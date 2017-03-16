/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:18:48 by jhalford          #+#    #+#             */
/*   Updated: 2016/12/12 14:58:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lst.h"

t_list	*ft_lst_at(t_list *list, unsigned int nbr)
{
	unsigned int	i;

	if (!list)
		return (NULL);
	i = 0;
	while (i < nbr && list)
	{
		list = list->next;
		i++;
	}
	return (list);
}
