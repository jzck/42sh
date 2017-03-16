/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_destroy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 19:30:17 by ariard            #+#    #+#             */
/*   Updated: 2017/03/16 22:13:50 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parser_destroy(t_parser *parser)
{
	parser->state = SUCCESS;	
	ft_lstdel(&parser->stack, &ft_lst_cfree);
	ft_lstdel(&data_singleton()->parser.heredoc_queue, &ft_lst_cfree);
	free(parser->new_sym);
	parser->new_sym = NULL; 
}
