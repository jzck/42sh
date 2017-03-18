/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:12:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/18 17:16:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			pop_stack(t_list **stack, t_sym erase_sym)
{
	t_sym		*head;
	t_list		*temp;

	while ((*stack) && (*(head = (*stack)->content) != erase_sym
		&& *head != TERMINUS))
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		ft_lstdelone(&temp, &sym_free);
	}
	if ((*stack) && *(head = (*stack)->content) != TERMINUS)
	{
		temp = *stack;
		(*stack) = (*stack)->next;
		ft_lstdelone(&temp, &sym_free);
	}
	else
		return (1);
	return (0);
}
