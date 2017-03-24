/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/16 20:25:08 by ariard            #+#    #+#             */
/*   Updated: 2017/03/24 17:07:56 by gwojda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	lexer_destroy(t_lexer *lexer)
{
	ft_strdel(&lexer->str);
	lexer->pos = 0;
	lexer->state = 0;
	ft_lstdel(&lexer->stack, ft_lst_cfree);
	lexer->heredoc_stack = NULL;
}
