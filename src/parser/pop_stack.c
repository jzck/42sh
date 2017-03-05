/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:12:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/05 16:28:52 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			pop_stack(t_list **stack, t_sym erase_sym)
{
	t_sym		*head;
	t_list		*temp;

	head = (*stack)->content;
	while ((*stack) && *head != erase_sym)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		ft_lstdelone(&temp, NULL);
		head = (*stack)->content;
	}
	temp = *stack;
	(*stack) = (*stack)->next;
	ft_lstdelone(&temp, NULL);
	return (0);
}	
