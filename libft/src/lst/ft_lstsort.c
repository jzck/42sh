/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/09 12:29:58 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstsort(t_list **begin_list, int (*cmp)())
{
	t_list	**indirect;
	t_list	*tmp;
	t_list	*tmp2;

	indirect = begin_list;
	if (!*begin_list)
		return ;
	while (*indirect && (*indirect)->next)
	{
		if ((*cmp)((*indirect)->content, (*indirect)->next->content) > 0)
		{
			tmp = *indirect;
			tmp2 = (*indirect)->next;
			(*indirect)->next = (*indirect)->next->next;
			*indirect = tmp2;
			(*indirect)->next = tmp;
			indirect = begin_list;
		}
		else
			indirect = &(*indirect)->next;
	}
}
