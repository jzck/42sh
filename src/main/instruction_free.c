/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_free.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gwojda <gwojda@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 15:54:59 by gwojda            #+#    #+#             */
/*   Updated: 2017/03/15 16:06:34 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	instruction_free(t_list **token, t_parser *parser, t_btree **ast)
{
	ft_lstdel(token, &token_free);
	token = NULL;
	ft_lstdel(&parser->stack, NULL);
	btree_del(ast, &ast_free);
	ft_lstdel(&data_singleton()->heredoc_queue, &redir_free);
	ft_lstdel(&data_singleton()->exec.op_stack, &op_stack_free);
	return (0);
}
