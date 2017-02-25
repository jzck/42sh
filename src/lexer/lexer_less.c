/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/02/25 20:11:17 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_less(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	if (lexer->str[lexer->pos] == '&')
	{
		token->type = TK_LESSAND;
		token_append(token, lexer, 0, 0);
		lexer->pos++;
		return (lexer_lessand(alst, lexer));
	}
	if (lexer->str[lexer->pos] == '<')
	{
		token_free(token, 0);
		(*alst)->content = token_init();
		token->type = TK_DLESS;
		lexer->pos++;
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
