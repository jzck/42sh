/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ariard <ariard@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:30:22 by ariard            #+#    #+#             */
/*   Updated: 2017/02/09 16:02:49 by ariard           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			ft_parse(t_btree **ast, t_list **token)
{
	t_sym			*new_sym;
	t_parstate		state;

	(void)ast;
	state = UNDEFINED;
	new_sym = ft_memalloc(sizeof(t_sym)); 
	while (*token)
	{
		produce_prim_sym(new_sym, token);
		DG("new sym : %s", read_state(*new_sym));
/*		if (eval_sym(head_stack, new_sym))
			state = ERROR;
		else
		{
			aggregate_sym(head_stack, new_sym, struct_sym);
			if (struct_sym)
				pop(struct_sym.sym);
			else if (!same_sym(new_sym, head_stack))
				push(new_sym);
		}
		build_tree(token, ast);
		if (head_stack == PROGRAM)
			state = PROGRAM;
		if (state == ERROR)
			return (error_syntax(token));
		if (state == PROGRAM)
			return (0);
*/	}
	return (0);
}
