/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_sorted_merge.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:40 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:40 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_sorted_merge(
		t_list **begin_list1,
		t_list *begin_list2,
		int (*cmp)())
{
	t_list	*tail;
	t_list	*head1;
	t_list	*head2;
	int		comp;

	if (!*begin_list1 || !begin_list2)
	{
		*begin_list1 = begin_list2 ? begin_list2 : *begin_list1;
		return ;
	}
	comp = (*cmp)(begin_list2->content, (*begin_list1)->content);
	head1 = (comp < 0) ? *begin_list1 : (*begin_list1)->next;
	head2 = (comp < 0) ? begin_list2->next : begin_list2;
	*begin_list1 = (comp < 0) ? begin_list2 : *begin_list1;
	tail = *begin_list1;
	while (head1 && head2)
	{
		comp = (*cmp)(head2->content, head1->content);
		tail->next = (comp < 0 ? head2 : head1);
		head1 = comp < 0 ? head1 : head1->next;
		head2 = comp < 0 ? head2->next : head2;
		tail = tail->next;
	}
	tail->next = head2 ? head2 : head1;
}
