/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_order_delsub.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:25 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 12:01:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_order_delsub(
		t_list **alst,
		t_list *sub,
		int (*cmp)(),
		void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	**indirect;

	indirect = alst;
	while (*indirect)
	{
		if ((*cmp)((*indirect)->content, sub->content) > 0)
		{
			sub = sub->next;
			continue ;
		}
		if ((*cmp)((*indirect)->content, sub->content) == 0)
		{
			tmp = *indirect;
			(*indirect) = (*indirect)->next;
			ft_lstdelone(&tmp, del);
			sub = sub->next;
		}
		indirect = &(*indirect)->next;
	}
}
