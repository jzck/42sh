/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:30:22 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 18:03:53 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			ft_parse(t_btree **ast, t_list **token)
{
	t_sym			*new_sym;
	t_sym			*stack;
	t_parstate		state;
	int				k;

	(void)ast;
	state = UNDEFINED;
	new_sym = ft_memalloc(sizeof(t_sym));
	stack = ft_memalloc(sizeof(t_sym) * 1000);
	*stack = 0;
	k = 0;
	while (*token)
	{
		produce_sym(new_sym, token);	
		if (eval_sym(*stack, *new_sym))
			state = ERROR;
		DG("head state : %s", read_state(*stack));
		else
		{
			k = aggregate_sym(*stack, new_sym)
			if (k)
			{
				while (k--)
					pop_stack(stack--);
				push_stack(++stack, new_sym);
			}
			else if (!superflous_sym(new_sym, stack))
				push_stack(++stack, new_sym);
		}
/*		if (head_stack == PROGRAM)
			state = PROGRAM;
		if (state == ERROR)
			return (error_syntax(token));
		if (state == PROGRAM)
			return (0);
		build_tree(token, ast);
*/	}
	ft_read_stack(stack);
	return (0);
}
