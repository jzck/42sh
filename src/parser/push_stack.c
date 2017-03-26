/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:48:30 by ariard            #+#    #+#             */
/*   Updated: 2017/03/26 21:35:32 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		push_stack(t_list **stack, t_sym sym)
{
	ft_lstadd(stack, ft_lstnew(&sym, sizeof(sym)));
	return (0);
}
