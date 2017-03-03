/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/03/03 17:56:07 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

static int	word_is_assignment(t_token *token)
{
	const int	len = ft_strlen(token->data);
	int			pos = -1;
	char		c;

	while (++pos < len)
	{
		if (is_char_esc(token->esc, token->data, token->data + pos))
			return (0);
		c = token->data[pos];
		if (!ft_isalnum(c) && c != '_' && c != '-')
			return (0);
	}
	return (1);
}

int			lexer_word(t_list **alst, t_lexer *lexer)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = TK_WORD;
	if ((state = get_state_global(lexer))
		|| (state = get_state_redir(lexer)))
	{
		lexer->state = state;
		return (lexer_lex(alst, lexer));
	}
	if (lexer->str[lexer->pos] == '=' && word_is_assignment(token))
	{
		lexer->state = ASSIGNEMENT_WORD;
		return (lexer_lex(alst, lexer));
	}
	token_append(token, lexer, 0, 0);
	lexer->pos++;
	return (lexer_lex(alst, lexer));
}
