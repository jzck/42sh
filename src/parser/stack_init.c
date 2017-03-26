/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:31:32 by ariard            #+#    #+#             */
/*   Updated: 2017/03/26 21:37:19 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		stack_init(t_parser *parser)
{
	ft_lstdel(&parser->stack, ft_lst_cfree);
	/* parser->stack = NULL; */
	push_stack(&parser->stack, TERMINUS);
	push_stack(&parser->stack, LINEBREAK);
	if (!parser->new_sym && !(parser->new_sym = ft_memalloc(sizeof(t_sym))))
		return (-1);
	return (0);
}
