/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_reverse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <marvin@43.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 13:20:13 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 00:31:33 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lst_reverse(t_list **begin_list)
{
	t_list	*new_start;
	t_list	*tmp;

	new_start = NULL;
	while (*begin_list)
	{
		tmp = (*begin_list)->next;
		(*begin_list)->next = new_start;
		new_start = *begin_list;
		*begin_list = tmp;
	}
	*begin_list = new_start;
}
