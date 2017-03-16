/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:50:32 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:24 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list_ptr;

	if (*begin_list1)
	{
		list_ptr = *begin_list1;
		while (list_ptr->next)
			list_ptr = list_ptr->next;
		list_ptr->next = begin_list2;
	}
	else
		*begin_list1 = begin_list2;
}
