/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_last_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 16:15:34 by ariard            #+#    #+#             */
/*   Updated: 2017/03/22 16:38:19 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			keep_last_type(t_type *last, t_list *token)
{
	t_list	*tmp;

	if (!(tmp = ft_lstlast(token)))
		return ((*last = 0));
	return (*last = ((t_token *)tmp->content)->type);
}
