/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_order.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 19:20:45 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:19:13 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ld	*ft_ld_order(t_ld *ld, int (*f)(), void (*del)())
{
	int		swap;

	swap = 1;
	ld = ft_ld_front(ld);
	while (swap)
	{
		swap = 0;
		while (ld && ld->next)
		{
			if (f(ld->content, ld->next->content) > 0 && (swap = 1))
				ld = ft_ld_swap(ld);
			else if (!f(ld->content, ld->next->content))
				ft_ld_del(&ld, del);
			ld = ld->next;
		}
		ld = ft_ld_front(ld);
	}
	return (ld);
}
