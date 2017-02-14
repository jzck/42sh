/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/14 18:26:07 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_prodmatch		g_prodmatch[] =
{
	{TK_N_WORD, TK_DLESS, HERE_END},
	{TK_N_WORD, TK_DLESSDASH, HERE_END},
	{TK_N_WORD, TK_LESS, FILENAME},
	{TK_N_WORD, TK_LESSAND, FILENAME},
	{TK_N_WORD, TK_GREAT, FILENAME},
	{TK_N_WORD, TK_GREATAND, FILENAME},
	{TK_N_WORD, TK_DGREAT, FILENAME},
	{TK_N_WORD, TK_LESSGREAT, FILENAME},
	{TK_N_WORD, TK_CLOBBER, FILENAME},
	{TK_N_WORD, CMD_WORD, CMD_SUFFIX},
	{TK_N_WORD, CMD_NAME, CMD_SUFFIX},
	{TK_N_WORD, LINEBREAK, CMD_NAME},

	{TK_N_WORD, NEWLINE_LIST, CMD_NAME},
	{TK_N_WORD, TK_BANG, CMD_NAME},
	{TK_N_WORD, PIPE_SEMI_SEQUENCE, CMD_NAME},
	{TK_N_WORD, SEPARATOR_OP, CMD_NAME},
	{TK_N_WORD, IN, WORDLIST},
	{TK_N_WORD, CASE_LIST, PATTERN},
	{TK_N_WORD, TK_PAREN_OPEN, PATTERN},	
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
	{TK_SEMI, TERM, SEPARATOR_OP},
	{TK_SEMI, LIST, SEPARATOR_OP},
	{TK_SEMI, COMPOUND_LIST, SEPARATOR_OP},
	{TK_AMP, TERM, SEPARATOR_OP},
	{TK_AMP, LIST, SEPARATOR_OP},
	{TK_AMP, COMPOUND_LIST, SEPARATOR_OP},

	{0, 0, 0},
};

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst)
{
	t_token		*token;
	int			i;

	token = (*lst)->content;
	DG("produce stack : %s && token : %s", read_state(stack),
	read_state(token->type));
	i = 0;
	*new_sym = 0;
	while (g_prodmatch[i].new_sym)
	{
		if (token->type == g_prodmatch[i].token
			&& stack == g_prodmatch[i].stack)
		{
			DG("MATCH : %s", read_state(g_prodmatch[i].new_sym));
			*new_sym = g_prodmatch[i].new_sym;
		}
		i++;
	}
	if (!*new_sym)
		*new_sym = token->type;
	return (0);
}
