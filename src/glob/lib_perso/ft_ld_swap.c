/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/24 21:12:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/23 06:01:07 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_ld		*ft_ld_swap(t_ld *l_cur)
{
	t_ld	*l_next;
	t_ld	*l_prev;

	l_next = l_cur;
	if (l_cur && l_cur->next)
	{
		l_prev = l_cur->prev;
		l_next = l_cur->next;
		l_cur->next = l_next->next;
		if (l_cur->next)
			l_cur->next->prev = l_cur;
		l_cur->prev = l_next;
		l_next->next = l_cur;
		l_next->prev = l_prev;
		if (l_prev)
			l_prev->next = l_next;
	}
	return (l_next);
}
