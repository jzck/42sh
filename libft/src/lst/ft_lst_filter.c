/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_filter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:17 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/02 17:47:26 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lst_filter(
		t_list *lst,
		void const *data_ref,
		t_list *(*f)(t_list *elem, void const *))
{
	t_list	*out;
	t_list	*elem;

	out = NULL;
	while (lst)
	{
		if (f)
			elem = (*f)(lst, data_ref);
		else
			elem = lst;
		elem = ft_lstnew(elem->content, elem->content_size);
		ft_lsteadd(&out, elem);
		lst = lst->next;
	}
	return (out);
}
