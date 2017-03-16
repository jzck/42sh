/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:56 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 16:49:59 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		pop(t_list **lst)
{
	t_list	*top;
	int		item;

	top = *lst;
	item = top ? *(int*)top->content : 0;
	if (lst && *lst)
		*lst = (*lst)->next;
	ft_lstdelone(&top, ft_lst_cfree);
	return (item);
}
