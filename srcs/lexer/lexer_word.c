/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 12:07:11 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/11 15:38:03 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_word(t_list **alst, char *str)
{
	t_token		*token;
	t_lexstate	state;

	token = (*alst)->content;
	token->type = TK_N_WORD;
	if ((state = get_lexer_state(str)))
		return (ft_tokenize(alst, str, state));
	if (*str == '>')
		return (ft_tokenize(&(*alst)->next, str, GREAT));
	else if (*str == '<')
		return (ft_tokenize(&(*alst)->next, str, LESS));
	token_append(token, *str);
	return (ft_tokenize(alst, str + 1, WORD));
}
