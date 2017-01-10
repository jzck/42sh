/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:21 by jhalford          #+#    #+#             */
/*   Updated: 2017/01/10 14:50:37 by jhalford         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_default(t_list **alst, char *str)
{
	t_lexstate	state;
	t_token		*token;

	state = DEFAULT;
	if ((state = get_lexer_state(str)))
		return (ft_tokenize(alst, str, state));
	if (*str == '>')
		return (ft_tokenize(alst, str, GREAT));
	else if (*str == '<')
		return (ft_tokenize(alst, str, LESS));
	else if (ft_isdigit(*str))
		state = NUMBER;
	else
		state = WORD;
	token = (*alst)->content;
	token_append(token, *str);
	token->type = TK_N_WORD;
	return (ft_tokenize(alst, str + 1, state));
}
