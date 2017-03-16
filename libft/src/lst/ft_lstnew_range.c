/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_range.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:54 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:54 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew_range(int a, int b)
{
	t_list	*lst;

	if (a >= b)
		return (NULL);
	lst = NULL;
	while (a < b)
	{
		b--;
		ft_lstadd(&lst, ft_lstnew(&b, sizeof(int)));
	}
	return (lst);
}
