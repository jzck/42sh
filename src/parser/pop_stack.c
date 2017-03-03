/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 19:12:44 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 14:28:02 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			pop_stack(t_sym **stack, t_sym erase_sym)
{
	t_sym	*temp;

//	DG("pop until :%s", read_state(erase_sym));
	temp = *stack; 
	while (*temp != erase_sym)
		*temp-- = 0;
	*temp-- = 0;
	*stack = temp;
	return (0);
}	
