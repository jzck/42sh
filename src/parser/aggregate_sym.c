/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aggregate_sym.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:39:18 by ariard            #+#    #+#             */
/*   Updated: 2017/02/12 18:47:00 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_aggrematch		g_aggrematch[] =
{
	{TK_WORD, CMD_SUFFIX, CMD_SUFFIX, ALL, 0},
	{TK_WORD, TK_PIPE, PATTERN, ALL, 0},
	{TK_WORD, WORDLIST, WORDLIST, ALL, 0},

	{TK_ASSIGNEMENT_WORD, CMD_PREFIX,CMD_PREFIX, ALL, 0},

	{TK_FI, ELSE_PART, IF_CLAUSE, ALL, tant que IF},
	{TK_FI, COMPOUND_LIST, IF_CLAUSE, ALL, tant que IF},

	{TK_DONE, COMPOUND_LIST, DO_GROUP, ALL, tant DO},

	{TK_RBRACE, COMPOUND_LIST, BRACE_GROUP, ALL tant que LBRACE},

	{TK_PAREN_CLOSE, COMPOUND_LIST, SUBSHELL, ALL, tant que TK_PAREN_OPEN},
	
//watch this
	{SEPARATOR, COMPOUND_LIST, COMPOUND_LIST, ALL, 0},

	{LINEBREAK, TK_SEMI, SEPARATOR_OP, ALL, tant que TK_SEMI},
//do one
	{LINEBREAK, TK_PAREN_CLOSE, TK_ESAC, CASE_ITEM_NS, tant que pattern ou '('},
	
	{NEWLINE_LIST, NEWLINE_LIST, NEWLINE_LIST, ALL, tant que newline},
	{NEWLINE_LIST, NAME, SEPARATOR_SEP, ALL, 0},
	{NEWlINE_LIST, IN, SEPARATOR_SEP, ALL, 0},
	{NEWLINE_LIST, WORDLIST, SEPARATOR_SEP, ALL, 0},
	{NEWLINE_LIST, TERM, SEPARATOR, ALL, 0},
	{NEWLINE_LIST, COMPOUND_LIST, SEPARATOR, ALL, 0},

	{IO_HERE, ALL, IO_REDIRECT, ALL, TK_IO_NUMBER},
	
	{FILENAME, TK_LESS, IO_FILE, ALL, TK_LESS},
	{FILENAME, TK_LESSAND, IO_FILE, ALL, TK_LESSAND},
	{FILENAME, TK_GREAT, IO_FILE, ALL, TK_GREAT},
	{FILENAME, TK_GREATAND, IO_FILE, ALL, TK_GREATAND},
	{FILENAME, TK_DGREAT, IO_FILE, ALL, TK_DGREAT},
	{FILENAME, TK_LESGREAT, IO_FILE, ALL, TK_LESSGREAT},
	{FILENAME, TK_CLOBBER, IO_FILE, ALL, TK_CLOBBER},
	
	{IO_FILE, ALL, IO_REDIRECT, ALL, TK_IO_NUMBER},

	{IO_REDIRECT, COMPOUND_COMMAND, REDIRECT_LIST, ALL, REDIRECT_LIST},
	{IO_REDIRECT, CMD_SUFFIX, CMD_SUFFIX, ALL, CMD_SUFFIX},
	{IO_REDIRECT, CMD_NAME, CMD_SUFFIX, ALL, 0},
	{IO_REDIRECT, CMD_WORD, CMD_SUFFIX, ALL, 0},
	{IO_REDIRECT, CMD_PREFIX, CMD_PREFIX, ALL, CMD_PREFIX},
	{IO_REDIRECT, LINEBREAK, CMD_PREFIX, ALL, 0},
	{IO_REDIRECT, TK_BANG, CMD_PREFIX, ALL, 0},
	{IO_REDIRECT, SEPARATOR_OP, CMD_PREFIX, ALL, 0},
	{IO_REDIRECT, NEWLINE_LIST, CMD_PREFIX, ALL, 0},

	{REDIRECT_LIST, COMPOUND_COMMAND, COMPOUND_COMMAND, ALL, COMPOUND_COMMAND},
				
	{CMD_SUFFIX, CMD_WORD, SIMPLE_COMMAND, ALL, CMD_PREFIX},
	{CMD_SUFFIX, CMD_NAME, SIMPLE_COMMAND, ALL, CMD_NAME},

	{CMD_PREFIX, LINEBREAK, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_PREFIX, TK_BANG, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_PREFIX, SEPARATOR_OP, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_PREFIX, NEWLINE_LIST, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},

	{CMD_WORD, CMD_PREFIX, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 
		CMD_PREFIX},

	{CMD_NAME, LINEBREAK, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_NAME, TK_BANG, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_NAME, SEPARATOR_OP, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},
	{CMD_NAME, NEWLINE_LIST, SIMPLE_COMMAND, TK_NEWLINE ou TK_SEMI ou TK_AMP, 0},

	{0, 0, 0},
}

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
