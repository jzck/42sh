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

	{TK_COMPOUND_LIST, TK_DONE, DO_GROUP},
	{TK_COMPOUND_LIST, TK_RBRACE, BRACE_GROUP},
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
