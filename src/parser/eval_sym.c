/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_sym.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:26:30 by ariard            #+#    #+#             */
/*   Updated: 2017/02/10 16:57:46 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_stackmatch	g_stackmatch[] =
{
	{CMD_SUFFIX, TK_WORD},
	{TK_PIPE, TK_WORD},
	{CASE, TK_WORD},
	{WORDLIST, TK_WORD},

	{CMD_PREFIX, TK_ASSIGNEMENT_WORD},
	
	{REDIRECT_LIST, TK_IO_NUMBER},
	{CMD_SUFFIX, TK_IO_NUMBER},
	{CMD_PREFIX, TK_IO_NUMBER},
	{CMD_NAME, TK_IO_NUMBER},
	{CMD_WORD, TK_IO_NUMBER},
	{LINEBREAK, TK_IO_NUMBER},
	{TK_BANG, TK_IO_NUMBER},
	{SEPARATOR_OP, TK_IO_NUMBER},
	{NEWLINE_LIST, TK_IO_NUMBER},

	{TK_AND_IF, AND_OR},

	{TK_OR_IF, AND_OR},

	{TK_DSEMI, LINEBREAK},
	{TK_DSEMI, COMPOUND_LIST},

	{TK_DLESS, TK_IO_NUMBER},
	{TK_DLESS, REDIRECT_LIST},
	{TK_DLESS, CMD_SUFFIX},
	{TK_DLESS, CMD_PREFIX},
	{TK_DLESS, CMD_WORD},
	{TK_DLESS, CMD_NAME},
	{TK_DLESS, LINEBREAK},
	{TK_DLESS, TK_BANG},
	{TK_DLESS, SEPARATOR_OP},
	{TK_DLESS, NEWLINE_LIST},

	{TK_DLESSDASH, TK_IO_NUMBER},
	{TK_DLESSDASH, REDIRECT_LIST},
	{TK_DLESSDASH, CMD_SUFFIX},
	{TK_DLESSDASH, CMD_PREFIX},
	{TK_DLESSDASH, CMD_WORD},
	{TK_DLESSDASH, CMD_NAME},
	{TK_DLESSDASH, LINEBREAK},
	{TK_DLESSDASH, TK_BANG},
	{TK_DLESSDASH, SEPARATOR_OP},
	{TK_DLESSDASH, NEWLINE_LIST},
	
	{TK_DGREAT, TK_IO_NUMBER},
	{TK_DGREAT, REDIRECT_LIST},
	{TK_DGREAT, CMD_SUFFIX},
	{TK_DGREAT, CMD_PREFIX},
	{TK_DGREAT, CMD_WORD},
	{TK_DGREAT, CMD_NAME},
	{TK_DGREAT, LINEBREAK},
	{TK_DGREAT, TK_BANG},
	{TK_DGREAT, SEPARATOR_OP},
	{TK_DGREAT, NEWLINE_LIST},
	
	{TK_LESSAND, TK_IO_NUMBER},
	{TK_LESSAND, REDIRECT_LIST},
	{TK_LESSAND, CMD_SUFFIX},
	{TK_LESSAND, CMD_PREFIX},
	{TK_LESSAND, CMD_WORD},
	{TK_LESSAND, CMD_NAME},
	{TK_LESSAND, LINEBREAK},
	{TK_LESSAND, TK_BANG},
	{TK_LESSAND, SEPARATOR_OP},
	{TK_LESSAND, NEWLINE_LIST},

	{TK_GREATAND, TK_IO_NUMBER},
	{TK_GREATAND, REDIRECT_LIST},
	{TK_GREATAND, CMD_SUFFIX},
	{TK_GREATAND, CMD_PREFIX},
	{TK_GREATAND, CMD_WORD},
	{TK_GREATAND, CMD_NAME},
	{TK_GREATAND, LINEBREAK},
	{TK_GREATAND, TK_BANG},
	{TK_GREATAND, SEPARATOR_OP},
	{TK_GREATAND, NEWLINE_LIST},

	{TK_LESSGREAT, TK_IO_NUMBER},
	{TK_LESSGREAT, REDIRECT_LIST},
	{TK_LESSGREAT, CMD_SUFFIX},
	{TK_LESSGREAT, CMD_PREFIX},
	{TK_LESSGREAT, CMD_WORD},
	{TK_LESSGREAT, CMD_NAME},
	{TK_LESSGREAT, LINEBREAK},
	{TK_LESSGREAT, TK_BANG},
	{TK_LESSGREAT, SEPARATOR_OP},
	{TK_LESSGREAT, NEWLINE_LIST},

	{TK_CLOBBER, TK_IO_NUMBER},
	{TK_CLOBBER, REDIRECT_LIST},
	{TK_CLOBBER, CMD_SUFFIX},
	{TK_CLOBBER, CMD_PREFIX},
	{TK_CLOBBER, CMD_WORD},
	{TK_CLOBBER, CMD_NAME},
	{TK_CLOBBER, LINEBREAK},
	{TK_CLOBBER, TK_BANG},
	{TK_CLOBBER, SEPARATOR_OP},
	{TK_CLOBBER, NEWLINE_LIST},

	{TK_IF, LINEBREAK},
	{TK_IF, TK_BANG},
	{TK_IF, SEPARATOR_OP},
	{TK_IF, NEWLINE_LIST},
		
	{TK_THEN, COMPOUND_LIST},
	
	{TK_ELSE, COMPOUND_LIST},
	
	{TK_ELIF, COMPOUND_LIST},
				
	{TK_FI, ELSE_PART},
	{TK_FI, COMPOUND_LIST},	
	
	{TK_DO, COMPOUND_LIST},
	{TK_DO, NAME},
	{TK_DO, SEQUENTIAL_SEP},

	{TK_DONE, COMPOUND_LIST},

	{TK_CASE, LINEBREAK},
	{TK_CASE, TK_BANG},
	{TK_CASE, NEWLINE_LIST},
	{TK_CASE, SEPARATOR_OP},

	{TK_ESAC, CASE_LIST},
	{TK_ESAC, CASE_LIST_NS},
	{TK_ESAC, LINEBREAK},

	{TK_WHILE, LINEBREAK},
	{TK_WHILE, TK_BANG},
	{TK_WHILE, SEPARATOR_OP},
	{TK_WHILE, NEWLINE_LIST},

	{TK_UNTIL, LINEBREAK},
	{TK_UNTIL, TK_BANG},
	{TK_UNTIL, SEPARATOR_OP},
	{TK_UNTIL, NEWLINE_LIST},
	
	{TK_FOR, LINEBREAK},
	{TK_FOR, TK_BANG},
	{TK_FOR, SEPARATOR_OP},
	{TK_FOR, NEWLINE_LIST},

	{TK_LBRACE, LINEBREAK},
	{TK_LBRACE, TK_BANG},
	{TK_LBRACE, SEPARATOR_OP},
	{TK_LBRACE, NEWLINE_LIST},

	{TK_RBRACE, COMPOUND_LIST},

	{TK_BANG, LINEBREAK},
	{TK_BANG, SEPARATOR_OP},
	{TK_BANG, NEWLINE_LIST},
	
	{TK_IN, LINEBREAK},	
	{0, 0},
};

int			eval_sym(t_sym stack, t_sym new_sym)
{
	int				i;

	DG("eval head %s && sym %s", read_state(stack), read_state(new_sym));
	i = 0;
	while (g_stackmatch[i].top)
	{
		if (stack == g_stackmatch[i].under
			&& new_sym == g_stackmatch[i].top)
			return (0);
		i++;
	}
	return (1);
}
