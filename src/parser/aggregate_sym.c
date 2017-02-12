/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregate_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:39:18 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 20:19:29 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_aggrematch		g_aggrematch[] =
{
	{CMD_SUFFIX, TK_WORD, CMD_SUFFIX},
	{TK_PIPE, TK_WORD, PATTERN},
	{WORDLIST, TK_WORD, WORDLIST},

	{CMD_PREFIX, TK_ASSIGNEMENT_WORD, CMD_PREFIX},

	{ELSE_PART, TK_FI, IF_CLAUSE},
	{COMPOUND_LIST, TK_FI, IF_CLAUSE},	

	{COMPOUND_LIST, TK_DONE, DO_GROUP},
	{COMPOUND_LIST, TK_RBRACE, BRACE_GROUP},

	{TK_PAREN_CLOSE, COMPOUND_LIST, SUBSHELL, 2},
	
//watch this
	{SEPARATOR, COMPOUND_LIST, COMPOUND_LIST, 1},

	{LINEBREAK, TK_SEMI, SEPARATOR_OP, 1},
//prediction one
	{LINEBREAK, TK_PAREN_CLOSE, TK_ESAC, CASE_ITEM_NS, tant que pattern ou '('},
	
	{NEWLINE_LIST, NEWLINE_LIST, NEWLINE_LIST, ALL, tant que newline},
	{NEWLINE_LIST, NAME, SEPARATOR_SEP, ALL, 0},
	{NEWlINE_LIST, IN, SEPARATOR_SEP, ALL, 0},
	{NEWLINE_LIST, WORDLIST, SEPARATOR_SEP, ALL, 0},
	{NEWLINE_LIST, TERM, SEPARATOR, ALL, 0},
	{NEWLINE_LIST, COMPOUND_LIST, SEPARATOR, ALL, 0},

	{0, 0, 0},

int			aggregate_sym(t_sym **stack, t_sym *new_sym)
{
	DG("aggregate head %s && sym %s", read_state(**stack), read_state(*new_sym));
	if (**stack == 0  && *new_sym == CMD_NAME)
	{
		*new_sym = SIMPLE_COMMAND;
		aggregate_sym(stack, new_sym);
	}
	if (**stack == 0 && *new_sym == SIMPLE_COMMAND)
		*new_sym = PROGRAM;
	return (0);
}
