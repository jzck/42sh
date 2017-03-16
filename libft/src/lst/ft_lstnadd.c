/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:51 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:52 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstnadd(t_list **alst, t_list *new, int n)
{
	t_list	*lst;
	int		i;

	lst = *alst;
	if (lst)
	{
		i = 0;
		while (lst->next && i < n)
		{
			lst = lst->next;
			i++;
		}
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
	else
		*alst = new;
}
