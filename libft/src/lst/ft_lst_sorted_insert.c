/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted_insert.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:39 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:39 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_sorted_insert(t_list **begin_list, t_list *insert, int (*cmp)())
{
	t_list	*link;

	link = *begin_list;
	if (!link || (*cmp)(insert->content, link->content) < 0)
	{
		*begin_list = insert;
		insert->next = link ? link : NULL;
		return ;
	}
	while (link->next)
	{
		if ((*cmp)(insert->content, link->content) > 0
			&& (*cmp)(insert->content, link->next->content) <= 0)
		{
			insert->next = link->next;
			link->next = insert;
			return ;
		}
		link = link->next;
	}
	link->next = insert;
	insert->next = NULL;
}
