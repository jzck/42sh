/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_newline.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 23:19:46 by ariard            #+#    #+#             */
/*   Updated: 2017/03/20 15:25:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_newline(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	if (token->type)
		return (lexer_lex(&(*alst)->next, lexer));
	lexer->pos++;
	token->type = TK_NEWLINE;
	return (lexer_lex(&(*alst)->next, lexer));
}
