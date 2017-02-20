/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   produce_sym.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:58:34 by ariard            #+#    #+#             */
/*   Updated: 2017/02/20 22:37:22 by jhalford         ###   ########.fr       */
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
	{TK_WORD, CMD_SUPERIOR, CMD_SUFFIX},
	{TK_WORD, LINEBREAK, CMD_NAME},
	{TK_WORD, TK_PIPE, CMD_NAME},
	{TK_WORD, AND_OR, CMD_NAME},
	{TK_WORD, AND_OR_MAJOR, CMD_NAME},
	{TK_WORD, TK_WHILE, CMD_NAME},
	{TK_WORD, TK_UNTIL, CMD_NAME},
	{TK_WORD, TK_DO, CMD_NAME},
	{TK_WORD, TK_IF, CMD_NAME},
	{TK_WORD, TK_THEN, CMD_NAME},
	{TK_WORD, TK_ELIF, CMD_NAME},
	{TK_WORD, TK_ELSE, CMD_NAME},
	{TK_WORD, COMPOUND_LIST, CMD_NAME},
	{TK_WORD, COMPLETE_CONDITION, CMD_NAME},
	{TK_WORD, NEWLINE_LIST, CMD_NAME},
	{TK_WORD, TK_BANG, CMD_NAME},
	{TK_WORD, PIPE_SEMI_SEQUENCE, CMD_NAME},
	{TK_WORD, SEPARATOR_OP, CMD_NAME},
	{TK_WORD, IN, WORDLIST},
	{TK_WORD, CASE_LIST, PATTERN},
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
	{TK_NEWLINE, TK_DO, NEWLINE_LIST},
	{TK_NEWLINE, TK_WHILE, NEWLINE_LIST},
	{TK_NEWLINE, TK_UNTIL, NEWLINE_LIST},
	{TK_NEWLINE, TK_IF, NEWLINE_LIST},
	{TK_NEWLINE, TK_FI, NEWLINE_LIST},
	{TK_NEWLINE, TK_ELIF, NEWLINE_LIST},
	{TK_NEWLINE, TK_ELSE, NEWLINE_LIST},
	{TK_NEWLINE, TK_THEN, NEWLINE_LIST},
	{TK_NEWLINE, CMD_NAME, NEWLINE_LIST},
	{TK_NEWLINE, COMPLETE_COMMANDS, NEWLINE_LIST},
	{TK_NEWLINE, LINEBREAK, NEWLINE_LIST},
	{TK_NEWLINE, CMD_SUPERIOR, LINEBREAK},
	{TK_NEWLINE, PIPE_SEMI_SEQUENCE, LINEBREAK},
	{TK_NEWLINE, COMPOUND_LIST, NEWLINE_LIST},
	{TK_NEWLINE, COMPLETE_CONDITION, NEWLINE_LIST},
	{TK_NEWLINE, CONDITION, NEWLINE_LIST},
	{TK_SEMI, CMD_SUPERIOR, SEPARATOR_OP},
	{TK_SEMI, TERM, SEPARATOR_OP},
	{TK_SEMI, LIST, SEPARATOR_OP},
	{TK_SEMI, PIPE_SEMI_SEQUENCE, SEPARATOR_OP},
	{TK_AMP, CMD_SUPERIOR, SEPARATOR_OP},
	{TK_AMP, TERM, SEPARATOR_OP},
	{TK_AMP, LIST, SEPARATOR_OP},

	{0, 0, 0},
};

int		produce_sym(t_sym stack, t_sym *new_sym, t_list **lst)
{
	t_token		*token;
	int			i;

	token = (*lst)->content;
//	DG("produce stack : %s && token : %s", read_state(stack),
//	read_state(token->type));
	i = 0;
	*new_sym = 0;
	while (g_prodmatch[i].new_sym)
	{
		if (token->type == g_prodmatch[i].token
			&& stack == g_prodmatch[i].stack)
		{
//			DG("MATCH : %s", read_state(g_prodmatch[i].new_sym));
			*new_sym = g_prodmatch[i].new_sym;
		}
		i++;
	}
	if (!*new_sym)
		*new_sym = token->type;
	return (0);
}
