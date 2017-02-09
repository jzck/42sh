/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 17:58:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int		produce_sym(t_sym *new_sym, t_list **lst)
{
	t_token		*token;

	token = (*lst)->content;
	if (token->type == TK_N_WORD)
		*new_sym = CMD_NAME;
	else if (token->type == TK_NEWLINE)
		*new_sym = NEWLINE_LIST;
	else if (token->type == TK_DLESS)
		*new_sym = SYM_DLESS;
	else if (token->type == TK_DGREAT)
		*new_sym = SYM_DGREAT;
	else if (token->type == TK_GREATAND)
		*new_sym = SYM_GREATAND;
	else if (token->type == TK_GREAT)
	   *new_sym = SYM_GREAT;
	else if (token->type == TK_LESSAND)
		*new_sym = SYM_LESSAND;
	else if (token->type == TK_LESS)
		*new_sym = SYM_LESS;
	return (0);
}
