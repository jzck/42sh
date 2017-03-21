/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ld_del.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wescande <wescande@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:54:53 by wescande          #+#    #+#             */
/*   Updated: 2017/03/21 18:26:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_ld_del(t_ld **ld, void (*del)())
{
	t_ld	*next;
	t_ld	*prev;

	if (!ld || !*ld)
		return ;
	next = (*ld)->next;
	prev = (*ld)->prev;
	if ((*ld)->content && del)
		del(&(*ld)->content);
	free(*ld);
	if (next)
		next->prev = prev;
	if (prev)
	{
		prev->next = next;
		*ld = prev;
	}
	else
		*ld = next;
}
