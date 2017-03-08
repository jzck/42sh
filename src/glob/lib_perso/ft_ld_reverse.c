/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 14:16:04 by wescande          #+#    #+#             */
/*   Updated: 2017/03/07 21:20:35 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ld_reverse(t_ld **lst)
{
	t_ld	*l_prev;
	t_ld	*l_next;
	t_ld	*l_cur;

	l_cur = ft_ld_front(*lst);
	l_prev = NULL;
	while (l_cur)
	{
		l_next = l_cur->next;
		l_cur->next = l_prev;
		l_cur->prev = l_next;
		l_prev = l_cur;
		l_cur = l_next;
	}
	*lst = l_prev;
}
