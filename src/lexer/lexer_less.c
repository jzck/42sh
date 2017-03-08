/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_less.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:06:53 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/08 13:27:33 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		lexer_less(t_list **alst, t_lexer *lexer)
{
	t_token		*token;

	token = (*alst)->content;
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
		token->type = TK_DLESS;
		push(&lexer->stack, DLESS);
		lexer->pos++;
		lexer->state = DEFAULT;
		ft_lsteadd(&lexer->heredoc_stack, ft_lstnew(alst, sizeof(alst)));
		return (lexer_lex(&(*alst)->next, lexer));
	}
	token->type = TK_LESS;
	lexer->state = DEFAULT;
	return (lexer_lex(&(*alst)->next, lexer));
}
