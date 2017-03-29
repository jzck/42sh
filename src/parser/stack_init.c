/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:31:32 by ariard            #+#    #+#             */
/*   Updated: 2017/03/29 13:27:26 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		stack_init(t_parser *parser)
{
	push_stack(&parser->stack, TERMINUS);
	push_stack(&parser->stack, LINEBREAK);
	if (!parser->new_sym && !(parser->new_sym = ft_memalloc(sizeof(t_sym))))
		return (-1);
	return (0);
}
