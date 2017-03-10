/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_greatand.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 11:56:58 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/10 13:45:47 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_greatand(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token->type = TK_GREATAND;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
