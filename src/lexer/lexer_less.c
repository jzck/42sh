/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/09 20:37:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_less(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, lexer, 0, 0);
	if (lexer->str[lexer->pos + 1] == '&')
	{
		token->type = TK_LESSAND;
		lexer->pos++;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_lessand(alst, lexer));
	}
	if (lexer->str[lexer->pos + 1] == '<')
	{
		token_free(token, 0);
		(*alst)->content = token_init();
		token->type = TK_DLESS;
		lexer->pos += 2;
		push(&lexer->stack, DLESS);
		lexer->state = DEFAULT;
		ft_lsteadd(&lexer->heredoc_stack, ft_lstnew(alst, sizeof(alst)));
		return (lexer_lex(&(*alst)->next, lexer));
	}
	else
	{
		token->type = TK_LESS;
		lexer->state = DEFAULT;
		return (lexer_lex(&(*alst)->next, lexer));
	}
}
