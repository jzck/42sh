/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/21 15:42:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	if (!(elem = (t_list *)ft_malloc(sizeof(*elem))))
		return (NULL);
	elem->content = (*f)(lst->content);
	elem->next = ft_lstmap(lst->next, f);
	return (elem);
}
