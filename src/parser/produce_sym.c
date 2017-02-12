/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/12 17:41:45 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_prodmatch		g_prodmatch[] =
{
	{TK_WORD, TK_DLESS, HERE_END},
	{TK_WORD, TK_DLESSDASH, HERE_END},
	{TK_WORD, TK_LESS, FILENAME},
	{TK_WORD, TK_LESSAND, FILENAME},
	{TK_WORD, TK_GREAT, FILENAME},
	{TK_WORD, TK_GREATAND, FILENAME},
	{TK_WORD, TK_DGREAT, FILENAME},
	{TK_WORD, TK_LESSGREAT, FILENAME},
	{TK_WORD, TK_CLOBBER, FILENAME},
	{TK_WORD, CMD_WORD, CMD_SUFFIX},
	{TK_WORD, CMD_NAME, CMD_SUFFIX},
	{TK_WORD, LINEBREAK, CMD_NAME},
	{TK_WORD, NEWLINE_LIST, CMD_NAME},
	{TK_WORD, IN, WORDLIST},
	{{TK_WORD, CASE_LIST, PATTERN},
	{TK_WORD, TK_PAREN_OPEN, PATTERN},	
	
	{TK_ASSIGNEMENT_WORD, LINEBREAK, CMD_PREFIX},
	{TK_ASSIGNEMENT_WORD, TK_BANG, CMD_PREFIX},
	{TK_ASSIGNEMENT_WORD, SEPARATOR_OP, CMD_PREFIX},
	{TK_ASSIGNEMENT_WORD, NEWLINE_LIST, CMD_PREFIX},

	{TK_NAME, LINEBREAK, FNAME},
	{TK_NAME, TK_BANG, FNAME},
	{TK_NAME, SEPARATOR_OP, FNAME},
	{TK_NAME, NEWLINE_LIST, FNAME},
	{TK_NAME, TK_FOR, NAME},

	{TK_NEWLINE, COMPLETE_COMMANDS, NEWLINE_LIST},
	{TK_NEWLINE, LINEBREAK, NEWLINE_LIST},
	
	{0, 0, 0},
};

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst)
{
	t_token		*token;
	int			i;

	token = (*lst)->content;
	i = 0;
	*new_sym = NULL;
	while (g_prodmatch[i].new_sym)
	{
		if (token->type == g_prodmatch[i].token
			&& stack & g_prodmatch[i].stack)
			*new_sym = g_prodmatch[i].new_sym;
		i++;
	}
	if (!*new_sym)
		*new_sym = token->type;
	return (0);
}
