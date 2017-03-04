/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:48:30 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 14:28:09 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

//int		push_stack(t_sym *stack, t_sym new_sym)
int		push_stack(t_list **stack, t_sym sym)
{
	ft_lstadd(stack, ft_lstnew(&sym, sizeof(sym)));
//	*stack = sym;
	return (0);
}
