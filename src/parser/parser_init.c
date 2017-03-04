/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:14:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/03 14:28:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		parser_init(t_parser *parser)
{
	parser->state = SUCCESS;
	parser->new_sym = ft_memalloc(sizeof(t_sym));
	push_stack(&parser->stack, TERMINUS);
	push_stack(&parser->stack, LINEBREAK);
//	parser->stack = ft_memalloc(sizeof(t_sym) * 1000);
//	push_stack(parser->stack, LINEBREAK);
}
