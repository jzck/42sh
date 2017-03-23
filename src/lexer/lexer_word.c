/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/23 03:39:38 by wescande         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			lexer_word(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = token->type ? token->type : TK_WORD;
	if (lexer->str[lexer->pos] != '!'
		&& ((state = get_state_global(lexer))
		|| (state = get_state_redir(lexer))))
		lexer->state = state;
	else if (lexer->str[lexer->pos] == '='
			&& word_is_assignment((char *[]){token->data, (char *)token->esc}))
	{
		token->type = TK_ASSIGNMENT_WORD;
		token_append(token, lexer, 1, 0);
		lexer->pos++;
	}
	else
	{
		token_append(token, lexer, 0, 0);
		lexer->pos++;
	}
	return (lexer_lex(alst, lexer));
}
