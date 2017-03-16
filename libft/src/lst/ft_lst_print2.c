/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_print2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 11:09:29 by jhalford          #+#    #+#             */
/*   Updated: 2016/11/04 11:09:29 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_print2(t_list *list, void (*printer)())
{
	t_list	*list2;

	while (list)
	{
		ft_putendl("---");
		list2 = *(t_list**)list->content;
		while (list2)
		{
			ft_putstr("[");
			(*printer)(*(int *)list2->content);
			ft_putstr("]->");
			list2 = list2->next;
		}
		ft_putendl("X");
		ft_putendl("---");
		ft_putendl(" |");
		ft_putendl(" V");
		list = list->next;
	}
	ft_putendl(" X\n");
}
