/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 16:14:04 by ariard            #+#    #+#             */
/*   Updated: 2017/03/29 13:27:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		parser_init(t_parser *parser)
{
	parser->state = SUCCESS;
	parser->new_sym = NULL;
	parser->stack = NULL;
	parser->heredoc_queue = NULL;
}
