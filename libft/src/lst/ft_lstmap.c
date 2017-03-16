/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 12:03:14 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *))
{
	t_list	*elem;

	if (!lst)
		return (NULL);
	elem = ft_lstnew((*f)(lst->content), lst->content_size);
	elem->next = ft_lstmap(lst->next, f);
	return (elem);
}
