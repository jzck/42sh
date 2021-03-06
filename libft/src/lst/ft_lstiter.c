/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 14:57:19 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/11 16:17:43 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstiter(t_list *lst, int (*f)())
{
	while (lst)
	{
		if ((*f)(lst->content))
			return (1);
		lst = lst->next;
	}
	return (0);
}
