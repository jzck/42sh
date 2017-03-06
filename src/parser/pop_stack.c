/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:12:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/06 17:09:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			pop_stack(t_list **stack, t_sym erase_sym)
{
	t_sym		*head;
	t_list		*temp;

	while ((*stack) && *(head = (*stack)->content) != erase_sym)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		ft_lstdelone(&temp, NULL);	
	}
	if (*stack)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		ft_lstdelone(&temp, NULL);
	}
	else
		return (1);
	return (0);
}	
