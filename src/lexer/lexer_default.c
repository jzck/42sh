/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_default.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhalford <jack@crans.org>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:36:21 by jhalford          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2017/01/26 18:16:02 by ariard           ###   ########.fr       */
=======
/*   Updated: 2017/01/27 15:53:10 by wescande         ###   ########.fr       */
>>>>>>> master
/*                                                                            */
/* ************************************************************************** */

#include "lexer.h"

int		lexer_default(t_list **alst, char *str)
{
	t_lexstate	state;
	t_token		*token;

	if ((state = get_lexer_state(str)))
		return (ft_tokenize(alst, str, state));
	if (*str == '>')
		return (ft_tokenize(alst, str, GREAT));
	else if (*str == '<')
		return (ft_tokenize(alst, str, LESS));
	else if (*str == '#')
		return (ft_tokenize(alst, str, COMMENT));
	else if (ft_isdigit(*str))
		state = NUMBER;
	else
		state = WORD;
	token = (*alst)->content;
<<<<<<< HEAD
=======
	token_append(token, *str, 0);
>>>>>>> master
	token->type = TK_N_WORD;
	return (ft_tokenize(alst, str, state));
}
